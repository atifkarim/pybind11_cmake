#include "base.hpp"

void Image_Core::Image_Size(uint32_t size_)
{
    size = size_;
}

void Image_Core::Print_Status()
{
    std::cout << "Size is : " << size << std::endl;
}
