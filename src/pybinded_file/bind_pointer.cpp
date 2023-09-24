/**
 * This file binds types from pointer.hpp
*/

#include "pointer.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/complex.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

void bind_pointer(py::module &m) {

    // Function binding to increment value using pointer
    m.def("pointer_increment",
      [](int x, int y, int z)
      {
          pointer_increment(&x, y, &z);
          return std::make_tuple(x, y, z);
      });

    // Function binding to update array value using pointer
    m.def("modify_array", [](py::array_t<unsigned int> arr) {
        // Extract the length from the array's shape
        size_t p_arr_len = arr.shape(0);

        // Access the data as a pointer
        unsigned int* p_arr = static_cast<unsigned int*>(arr.mutable_data(0));

        // Call the original C++ function
        modify_array(p_arr, p_arr_len);
    }, "Modify an array", py::arg("p_arr"));


}