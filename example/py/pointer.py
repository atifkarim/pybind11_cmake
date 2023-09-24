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

# Call the C++ function with both arguments
pybind_cpp_module.modify_array(x_array)
print("Now array: ", x_array)