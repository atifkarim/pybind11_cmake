/**
 * This file binds types from pointer.hpp
*/

#include "pointer.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/complex.h>
#include <pybind11/stl.h>

namespace py = pybind11;

void bind_pointer(py::module &m) {
    m.def("pointer_increment",
      [](int x, int y, int z)
      {
          pointer_increment(&x, y, &z);
          return std::make_tuple(x, y, z);
      });
}