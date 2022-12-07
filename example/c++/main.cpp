#include "child.hpp"

int main()
{
    Image_Core image_base("Panda");
    image_base.Image_Size(25);
    image_base.Print_Status();

    Image_Process image_process("Quala", "Picaso");
    image_process.Show_Date();
    uint32_t point[4] = {1,5,6,8};
    image_process.Image_Coordinate(point);
    image_process.Print_Image_Coordinate();

    Image_Process::Sample_Enum sample_enum_value;
	sample_enum_value = Image_Process::Sample_Enum::A_2;
    image_process.Check_Enum(sample_enum_value);
    std::cout << "Fetched Enum Value: " << static_cast<uint32_t>(image_process.Check_Enum()) << std::endl;

    return 0;
}
