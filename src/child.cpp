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

void Image_Process::Check_Enum(Sample_Enum sample_enum)
{
	switch(sample_enum)
	{
	case Sample_Enum::A_0:
		enum_dummy_value = 0; break;
	case Sample_Enum::A_1:
		enum_dummy_value = 1; break;
	case Sample_Enum::A_2:
		enum_dummy_value = 2; break;
	default:
		throw std::runtime_error("Invalid enum data.");
	}
}

Image_Process::Sample_Enum Image_Process::Check_Enum() const
{
	return static_cast<Image_Process::Sample_Enum>(enum_dummy_value);
}
