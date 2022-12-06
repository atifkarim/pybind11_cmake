#include "base.hpp"
#include <iomanip>
#include <chrono>
#include <sstream>
#include <array>

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

		void Show_Date();
		std::array<uint32_t, 4> Image_Coordinate(uint32_t * coordinate_point);
		void Print_Image_Coordinate() const;

		virtual ~Image_Process(){}

	private:
		std::string user_name_;
		std::string current_time_;
		std::array<uint32_t, 4> point;
};
