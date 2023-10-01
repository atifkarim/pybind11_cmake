#include "pointer.hpp"
#include "iostream"

void pointer_increment(int *i, int j, int *k) {
    *i += 3;
    *k =  *i + j;
}

void modify_array(unsigned int * p_arr, unsigned int p_arr_len)
{
    std::cout << "Provided array value: ";
    for(unsigned int i = 0; i < p_arr_len; i++)
    {
        std::cout << *(p_arr + i) << "  "; 
    }
    std::cout << std::endl;

    std::cout << "Now modifying inside function" << std::endl;
    for(unsigned int i = 0; i < p_arr_len; i++)
    {
        *(p_arr + i) = *(p_arr + i) * 2; 
    }
}

int Color_Input(int * color_ip,
                int ** color_op,
                Color_Info * color_info)
{
    std::cout << "Color Number: " << color_info->color_number << std::endl;
    std::cout << "Inside function color_ip" << std::endl;
    for (unsigned int i = 0; i< color_info->color_number; i++)
        std::cout << *(color_ip + i) << " ";
    std::cout << std::endl;
    int* local_op_ = new int[9];

	for (unsigned int i = 0; i< color_info->color_number; i++)
	{
		local_op_[i] = *(color_ip + i);
	}
    std::cout << "Inside function local_op_" << std::endl;
    for (unsigned int i = 0; i< color_info->color_number; i++)
        std::cout << *(local_op_ + i) << " ";
    std::cout << std::endl;

	*color_op = &local_op_[0];
    std::cout << "Inside function color_info->color_box_number: " << *(color_info->color_box_number) << std::endl;
    *(color_info->color_box_number) = 8;
    return 1;
}

void Check_Struct(Child * obj)
{
    obj->age = 12;
    *(obj->number) = 123;
}