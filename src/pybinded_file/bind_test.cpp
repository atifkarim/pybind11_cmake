/**
 * This file binds types from test.hpp
*/

#include "test.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;

void bind_test(py::module &m) {
    m.def("print_msg", &print_msg);
    m.def("add", &add);
}