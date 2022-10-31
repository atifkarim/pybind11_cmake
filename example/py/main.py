import pybind_cpp_module

image_core_obj = pybind_cpp_module.Image_Core("Penguine")
image_core_obj.Image_Size(98)
image_core_obj.Print_Status()
