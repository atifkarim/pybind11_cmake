print("\n\n")
print("-"*10, " Python program is executing ", "-"*10)

import sys, os
sys.path.append("../../lib")

import pybind_cpp_module

image_core_obj = pybind_cpp_module.Image_Core("Penguin")
image_core_obj.Image_Size(98)
image_core_obj.Print_Status()


image_process_obj = pybind_cpp_module.Image_Process("Cow", "Heroku")
image_process_obj.Show_Date()
point = [1,2,3,5]
image_process_obj.Image_Coordinate(point)
image_process_obj.Print_Image_Coordinate()

# enum_object = pybind_cpp_module.Image_Process.Sample_Enum
# print("enum_object: ",enum_object)
# print(type(enum_object))
# print(enum_object.A_0)
image_process_obj.Check_Enum(pybind_cpp_module.Image_Process.Sample_Enum.__members__["A_0"])
print("Value of enum return: ", image_process_obj.Check_Enum().value)
print("Name of enum return : ", image_process_obj.Check_Enum().name)

image_container_object = pybind_cpp_module.Input_Container()
image_container_object.image_file_num = [2,5,8,7]
image_process_obj.Check_Image_File_Num(image_container_object)
print("Res: ", image_process_obj.Check_Image_File_Num())

# This executes print_msg function from bind_test 
pybind_cpp_module.print_msg("Hello py")

# This executes increment_value function from bind_reference 
s = 8
t = -5
s,t = pybind_cpp_module.increment_value(s,t)
print("value s: ", s , " t: ",t)

print("Result of add function", pybind_cpp_module.add(4,8))

from pointer import *