#include <iostream>
#include <string>

template <typename T1 = std::string, typename T2 = int>
class Image_Base{
public:

	Image_Base(T1 image_id_ = "No Name"): image_base_id{image_id_}{}
	virtual ~Image_Base() {}
	virtual int weight_kg(T2 weight) const = 0;

protected:
	T1 image_base_id;
};

class Image_Core{
	public:
		Image_Core () = delete;
		Image_Core(std::string name_)
		          : name{name_}
		{std::cout << "Image core gets " << name << std::endl;}

		// destructor is called
		virtual ~Image_Core(){}

		void Image_Size(uint32_t size_);
		void Print_Status();

	private:
		std::string name; // Image name
		uint32_t size; // Image size (will be displayed in MB unit)
};
