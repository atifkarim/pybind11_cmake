#include <iostream>
#include <string>

class Image_Core{
    public:
        Image_Core(std::string name_)
                   : name{name_}
                  {
                    std::cout << "Image core gets " << name << std::endl;
                  }

        // destructor is called
        virtual ~Image_Core(){}

        void Image_Size(uint32_t size_);
        void Print_Status();

    private:
        std::string name; // Image name
        uint32_t size; // Image size (will be displayed in MB unit)
};
