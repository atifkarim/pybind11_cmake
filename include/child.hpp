#include "base.hpp"
#include <iomanip>
#include <chrono>
#include <sstream>
#include <array>
#include <vector>

class Image_Process : public Image_Core
{
	public:
		Image_Process() = delete;

		Image_Process(std::string name, std::string user_name)
		             : Image_Core(name),
		               user_name_(user_name)
		               {std::cout << "Image Process is called" << std::endl;
		                time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		                std::stringstream current_time_stream;
		                current_time_stream << std::put_time(std::localtime(&now), "%F %T");
		                current_time_ = current_time_stream.str();
		               }

		enum class Sample_Enum
		{
			A_0 = 0,
			A_1 = 1,
			A_2 = 2,
		};

		struct Input_Container
		{
			std::vector<uint32_t> image_file_num;
		};

		void Show_Date();
		std::array<uint32_t, 4> Image_Coordinate(uint32_t * coordinate_point);
		void Print_Image_Coordinate() const;

		// Write using Enum
		void Check_Enum(Sample_Enum sample_enum);

		// Read back Enum
		Sample_Enum Check_Enum() const;

		void Check_Image_File_Num(Input_Container &input_container);
		uint32_t Check_Image_File_Num();

		virtual ~Image_Process(){}

	private:
		std::string user_name_;
		std::string current_time_;
		std::array<uint32_t, 4> point;
		uint32_t enum_dummy_value;
};
