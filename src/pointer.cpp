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