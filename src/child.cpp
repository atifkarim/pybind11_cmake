# include "child.hpp"

void Image_Process::Show_Date()
{
	std::cout << "Current Time: " << current_time_ << std::endl;
}

std::array<uint32_t, 4> Image_Process::Image_Coordinate(uint32_t * coordinate_point)
{
	for(uint32_t i = 0; i <4 ; i++)
	{
		point[i] = *(coordinate_point + i) * 4;
	}
	return point;
}

void Image_Process::Print_Image_Coordinate() const
{
	for (auto &x : point)
		std::cout << x << " ";
	std::cout << std::endl;

}
