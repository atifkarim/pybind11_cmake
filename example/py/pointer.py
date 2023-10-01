# Py file to demonstrate the usage of binded pointer.cpp

print("#"*10, "pointer","#"*10)

import numpy as np
import pybind_cpp_module

# Following function call pointer_increment()
p_1 = 12
p_2 = 23
p_3 = 9
p_1, p_2, p_3 = pybind_cpp_module.pointer_increment(p_1, p_2, p_3)
print("p_1: ",p_1, " p_2: ",p_2, " p_3: ",p_3)

# Following function call modify_array()
# Create a NumPy array
x_list = [1,2,5,6,4,6]
x_array = np.array(x_list, dtype=np.uint32)

# Get the length of the array
arr_len = len(x_list)

# Call the C++ function modify_array
pybind_cpp_module.modify_array(x_array)
print("Now array: ", x_array)

# Call the C++ function Color_Input
# It requires different arg to call than C++ function as py-binding 
# has written differently

color_info = pybind_cpp_module.Color_Info()
color_info.color_company_name = "Blue"
color_info.color_number = 9
color_info.color_box_number = 1
color_info.color_code = 2
color_ip = []
color_op = []
ret = 0
for i in range (9):
    color_ip.append(2 * i)

ret, color_op = pybind_cpp_module.Color_Input(color_ip, color_info)

print("ret: ", ret)
print("color_op: ", color_op)

# Call the C++ function Check_Struct
child_obj = pybind_cpp_module.Child()
child_obj.number = 8
ret_obj = pybind_cpp_module.Check_Struct(child_obj)
print("Age in py: ", ret_obj.age)
print("NUmber in py: ", ret_obj.number)
