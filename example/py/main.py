print("-"*10, " Python program is executing ", "-"*10)

import pybind_cpp_module

image_core_obj = pybind_cpp_module.Image_Core("Penguin")
image_core_obj.Image_Size(98)
image_core_obj.Print_Status()


image_process_obj = pybind_cpp_module.Image_Process("Cow", "Heroku")
image_process_obj.Show_Date()
point = [1,2,3,5]
image_process_obj.Image_Coordinate(point)
image_process_obj.Print_Image_Coordinate()
