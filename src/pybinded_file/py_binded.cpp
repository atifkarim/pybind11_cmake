#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include "child.hpp"
#include <pybind11/numpy.h>

namespace py = pybind11;

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
	    .def("Print_Image_Coordinate", &Image_Process::Print_Image_Coordinate);

	Pybind_Image_Base<std::string, int>(m, "std::string", "int");
}
