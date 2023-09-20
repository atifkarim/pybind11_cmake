#include "header_list.hpp"

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

    Image_Process::Input_Container input_container;
    input_container.image_file_num = {1,5,6,8};
    image_process.Check_Image_File_Num(input_container);
    std::cout << "Res: " << image_process.Check_Image_File_Num() << std::endl;

    {
        // This namespace will print from test.hpp
        print_msg("Hello Developer !!!");
        int res = add(8,9);
        std::cout << "Res: " << res << std::endl;
    }

    {
        // This namespace will increment value by reference
        int x = 9; int y = -8;
        increment_value(x,y);
        std::cout << "After reference operation x: " << x << " y: " << y << std::endl;
    }

    return 0;
}
