/**
 * This file binds types from pointer.hpp
*/

#include "pointer.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/complex.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <pybind11/iostream.h>
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

    // Bind struct Color_Info
    py::class_<Color_Info> Color_Info (m, "Color_Info");
    Color_Info
	    .def(py::init<>())
	    .def_property("color_company_name",
	                  [](::Color_Info &self) { return std::string(self.color_company_name); },
	                  [](::Color_Info &m, const std::string &py_name) {
	                      // Memory allocation for C-style string
	                      m.color_company_name = new char[py_name.size() + 1];
	                      std::strcpy(const_cast<char *>(m.color_company_name), py_name.c_str());
	                  })
	    .def_readwrite("color_number", &Color_Info::color_number)
        .def_readwrite("color_box_number", &Color_Info::color_box_number)
        .def_readwrite("color_code", &Color_Info::color_code)
	    // .def_property("color_box_number", [](::Color_Info &self) {return self.color_box_number;},
	    //                            [](::Color_Info &m, py::array_t<unsigned int> buffer){
	    //                                 py::buffer_info info = buffer.request();
	    //                                 m.color_box_number = static_cast<unsigned int *>(info.ptr);})
	    // .def_property("color_code", [](::Color_Info &self) {return self.color_code;},
	    //                            [](::Color_Info &m, py::array_t<unsigned int> buffer){
	    //                                 py::buffer_info info = buffer.request();
	    //                                 m.color_code = static_cast<unsigned int *>(info.ptr);})
                                        ;


    // Bind Color_Input function
    /**
     * This function  will be used in python side. Be careful regarding function argument as it is not
     * same as C++. In python passing double pointer is kind of tricky and that's why here the resultant
     * double pointer will be created internally and return from this function.
     * In short, it can be told that this function is inherit the name from C++, will do the same work
     * but function argument and return variable will be different
    */
    m.def("Color_Input",
	      [](py::array_t<int> color_ip,
	         ::Color_Info& color_info)
	    {
	        // Extract color_ip data as a C++ pointer
	        int* input_data = color_ip.mutable_data();

            // Get color_ip size
            int color_ip_len = color_ip.size();

	        // Initialize pointers for output data (this is for double pointer)
	        int* color_op = nullptr;

	        // Call the Color_Input function
	        int result = Color_Input(input_data, &color_op, &color_info);

	        // Create NumPy arrays from the color_op
	        py::array_t<int> py_color_op(color_ip_len);

	        // Copy data from C++ arrays to NumPy arrays
	        auto buffer_color_op = py_color_op.request();

	        int* ptr_color_op = static_cast<int*>(buffer_color_op.ptr);

	        for (unsigned int i = 0; i < color_ip_len; i++)
	        {
	            ptr_color_op[i] = color_op[i];
	        }

	        // Return a Python tuple with the result
	        return py::make_tuple(result, py_color_op);
	    }, "Color_Input function");


	// Bind struct Child
    py::class_<Child> Child (m, "Child");
    Child
	    .def(py::init<>())
        .def_readwrite("age", &Child::age)
	    .def_property("number",
	                  [](::Child &self) { return self.number; },
	                  [](::Child &m, py::array_t<int> buffer) {
	                      py::buffer_info info = buffer.request();
                          m.number = static_cast<int *>(info.ptr);
	                  });

	// Bind function Check_Struct
	// m.def("Check_Struct",
    //   [](::Child& obj)
    //   {
    //       Check_Struct(&obj);
    //       return std::make_tuple(obj);
    //   });
    m.def("Check_Struct", &Check_Struct);



}