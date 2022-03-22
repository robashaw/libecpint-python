# initialise package
def get_ecp_file(name):
    """Returns where the xml file of the ECP basis with
       the given name is, for use by ECPBasis.add_ecp_from_file
    """
    rootdir = pyecpint.__file__.replace("__init__.py", "data/")
    return rootdir + name + ".xml"
