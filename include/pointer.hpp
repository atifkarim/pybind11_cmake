/**
 * This file shows different operation with C++ pointer
*/

// #ifndef POINTER_H_
// #define POINTER_H_

// This function update a single variable value using pointer
void pointer_increment(int *i, int j, int *k);

// This function updates array value using pointer
/**
 * \param p_arr pointer pointed to array
 * \param p_arr_len length of array
*/
void modify_array(unsigned int * p_arr, unsigned int p_arr_len);

// This strcut is used to set value using different datatype. Later this struct will be passed to
// a function input arg 
struct Color_Info{
    const char *color_company_name;    // Random name for color
    unsigned int color_number; // Random number to chose color
    unsigned int *color_box_number; // Random box number to chose color
    unsigned int *color_code; // Array of color code
};

// This function accepts an array using pointer and then process and generates an array which will be pointed by
// color_op pointer.
/**
 * An use case of double pointer is depicted here^
*/
int Color_Input(int * color_ip,
                int ** color_op,
                Color_Info * color_info);


// #endif // POINTER_H_