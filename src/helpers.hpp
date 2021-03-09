// extends functionality of pybind11
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

/**
 * \brief Returns py:array<T> from vector<T>. Efficient as zero-copy.
 * - Uses std::move to obtain ownership of said vector and transfer everything to the heap.
 * - Only accepts parameter using std::move(...), or else the vector metadata on the stack will go out of scope (heap data will always be fine).
 * \tparam T Type.
 * \param passthrough Numpy array.
 * \return py::array_t<T> with a clean and safe reference to contents of Numpy array.
 */
template<typename T>
inline py::array_t<T> toPyArray(std::vector<T>&& passthrough)
{
	// Pass result back to Python.
	// Ref: https://stackoverflow.com/questions/54876346/pybind11-and-stdvector-how-to-free-data-using-capsules
	auto* transferToHeapGetRawPtr = new std::vector<T>(std::move(passthrough));
	// At this point, transferToHeapGetRawPtr is a raw pointer to an object on the heap. No unique_ptr or shared_ptr, it will have to be freed with delete to avoid a memory leak.

	// Alternate implementation: use a shared_ptr or unique_ptr, but this appears to be more difficult to reason about as a raw pointer (void *) is involved - how does C++ know which destructor to call?
	
	const py::capsule freeWhenDone(transferToHeapGetRawPtr, [](void *toFree) {				
		delete static_cast<std::vector<T> *>(toFree);
		//fmt::print("Free memory."); // Within Python, clear memory to check free: sys.modules[__name__].__dict__.clear()
	});
	
	auto passthroughNumpy = py::array_t<T>(/*shape=*/{transferToHeapGetRawPtr->size()}, /*strides=*/{sizeof(T)}, /*ptr=*/transferToHeapGetRawPtr->data(), freeWhenDone);
	return passthroughNumpy;	
} 