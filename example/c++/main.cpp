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
    return 0;
}
