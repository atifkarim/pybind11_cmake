#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include "child.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pybind_cpp_module, m)
{
	py::class_<Image_Core>(m, "Image_Core")
	    .def(py::init<std::string>())
	    .def("Image_Size", &Image_Core::Image_Size)
	    .def("Print_Status", &Image_Core::Print_Status,
	          py::call_guard<py::scoped_ostream_redirect, py::scoped_estream_redirect>());


	py::class_<Image_Process, Image_Core> Image_Process(m, "Image_Process");
	Image_Process
	    .def(py::init<std::string, std::string>())
	    .def("Show_Date", &Image_Process::Show_Date);
}
