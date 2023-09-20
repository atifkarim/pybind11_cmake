#include "pointer.hpp"
#include "iostream"

void pointer_increment(int *i, int j, int *k) {
    *i += 3;
    *k =  *i + j;
}