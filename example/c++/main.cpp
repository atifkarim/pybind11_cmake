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

    // This namespace will work for pointer.hpp -> modify_array
    {
        unsigned int p_arr[5] = {2,3,5,8,78};
        modify_array(p_arr, 5);
        std::cout << "Modifed array value : ";
        for (auto &x : p_arr)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    // The following portion will work with pointer.hpp -> Color_Input
    {
        Color_Info color_info;
        color_info.color_company_name = "Black";
        color_info.color_number = 9;
        unsigned int color_box_number_ = 9;
        color_info.color_box_number = &color_box_number_;
        std::cout << "color_info.color_box_number: " << *color_info.color_box_number << std::endl;
        unsigned int color_code_ [] = {10,2,20,30,325};
        color_info.color_code = color_code_;

        int * color_ip_ = new int [color_info.color_number];
        for(unsigned int i = 0; i < color_info.color_number; i++)
            color_ip_[i] =  2 * i;
        std::cout << "Color IP" << std::endl;
        for(unsigned int i = 0; i < color_info.color_number; i++)
            std::cout << *(color_ip_ + i) << " ";
        std::cout << std::endl;
        int * color_op_;
        Color_Input(color_ip_, &color_op_, &color_info);

        std::cout << "Resultant color_op_" << std::endl;
        for(unsigned int i = 0; i < color_info.color_number; i++)
            std::cout << *(color_op_ + i) << " ";
        std::cout << std::endl;
        std::cout << "Changed color_info.color_box_number: " << *color_info.color_box_number << std::endl;
        std::cout << std::endl;
    }

    // The following portion will work with pointer.hpp -> Check_Struct
    {
        Child obj;
        int number_ = 456;
        obj.number = &number_;
        std::cout << "before function calling number: " << *(obj.number) << std::endl;
        Check_Struct(&obj);
        std::cout << "age: " << obj.age << std::endl;
        std::cout << "number: " << *(obj.number) << std::endl;
    }

    return 0;
}
