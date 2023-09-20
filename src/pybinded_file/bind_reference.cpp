/**
 * This file binds types from test.hpp
*/

#include "reference.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;

void bind_reference(py::module &m) {
    m.def("increment_value",
      [](int x, int y)
      {
          increment_value(x, y);
          return std::make_tuple(x, y);
      });
}