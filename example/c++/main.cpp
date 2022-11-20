#include "child.hpp"

int main()
{
    Image_Core image_base("Panda");
    image_base.Image_Size(25);
    image_base.Print_Status();

    Image_Process image_process("Quala", "Picaso");
    image_process.Show_Date();
    return 0;
}
