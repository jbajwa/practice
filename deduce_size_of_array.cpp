#include <iostream>

// 1. when arrays are passed by reference, the
// compiler deduces the type as array and also
// deduces the size, that info can be used to get
// the size of array at runtime.
// 2. decltype autoi (c++14) will deduce the return type of
// the template function
template <typename T, std::size_t N>
decltype (auto) sizeofarray (T (&)[N])
{
    return N;
}

int main ()
{
    int mylist[] = {1,2,3,4,5,6,7,8};
    std::cout << "Size: " << sizeofarray (mylist) << std::endl;
    return 0;
}
