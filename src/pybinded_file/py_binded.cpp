#include "header_list.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>

namespace py = pybind11;

void bind_test(py::module &m);
void bind_reference(py::module &m);
void bind_pointer(py::module &m);

template <typename T1 = std::string, typename T2 = int>
void Pybind_Image_Base(py::module &m, const std::string& typestr1, const std::string& typestr2)
{
	using IMAGE_BASE_CONSTR = Image_Base_Template<T1, T2>;

	class PyVirtualClass_Abstract : public Image_Base_Template<T1, T2>
	{
	public:
		using Image_Base_Template<T1, T2>::Image_Base_Template;
		typedef Image_Base_Template<T1, T2> macro_type;

		// Trampoline (need one for each virtual function)
		int weight_kg(T2 weight) const override
		{
		PYBIND11_OVERRIDE_PURE(
			int,           // Function Return type
			macro_type,    // Class Type where this function is declared
			weight_kg,     // Name of the function. Same name will be used in driver code also
			weight         // Function Argument
			);
		}
	};

	/// Create template instance and bind it as python function including the functions. In addition set the default reference pointer type to shared_ptr in C++ instead of unique_ptr (default).
	py::class_<Image_Base_Template<T1, T2>, PyVirtualClass_Abstract>(m, "Image_Base_Template")
	.def(py::init<std::string>())
	.def("weight_kg", &Image_Base_Template <T1, T2>::weight_kg);
}

PYBIND11_MODULE(pybind_cpp_module, m)
{
    bind_test(m);
	bind_reference(m);
	bind_pointer(m);

	py::class_<Image_Core>(m, "Image_Core")
	    .def(py::init<std::string>())
	    .def("Image_Size", &Image_Core::Image_Size)
	    .def("Print_Status", &Image_Core::Print_Status,
	          py::call_guard<py::scoped_ostream_redirect, py::scoped_estream_redirect>());


	py::class_<Image_Process, Image_Core> Image_Process(m, "Image_Process");
	Image_Process
	    .def(py::init<std::string, std::string>())
	    .def("Show_Date", &Image_Process::Show_Date)
	    .def("Image_Coordinate", [](class Image_Process &m, py::array_t<uint32_t> buffer){
	                                py::buffer_info info = buffer.request();
	                                m.Image_Coordinate(static_cast<uint32_t *>(info.ptr));})
	    .def("Print_Image_Coordinate", &Image_Process::Print_Image_Coordinate,
		                               py::call_guard<py::scoped_ostream_redirect,
		                               py::scoped_estream_redirect>())
	    .def("Check_Enum", py::overload_cast<Image_Process::Sample_Enum>(&Image_Process::Check_Enum))
	    .def("Check_Enum", py::overload_cast<>(&Image_Process::Check_Enum, py::const_))
	    .def("Check_Image_File_Num", py::overload_cast<Image_Process::Input_Container &>(&Image_Process::Check_Image_File_Num))
	    .def("Check_Image_File_Num", py::overload_cast<>(&Image_Process::Check_Image_File_Num));

	py::enum_<Image_Process::Sample_Enum>(Image_Process, "Sample_Enum")
	    .value("A_0", Image_Process::Sample_Enum::A_0)
	    .value("A_1", Image_Process::Sample_Enum::A_1)
	    .value("A_2", Image_Process::Sample_Enum::A_2)
	    .export_values();

	py::class_<Image_Process::Input_Container> Input_Container (m, "Input_Container", py::buffer_protocol());
	Input_Container.def(py::init<>())
	    .def_property("image_file_num", [](Image_Process::Input_Container &self) {return self.image_file_num;},
	                                    [](Image_Process::Input_Container &self,
	                                    std::vector<uint32_t>buffer) {self.image_file_num = buffer;});

	Pybind_Image_Base<std::string, int>(m, "std::string", "int");
}
