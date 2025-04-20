#include <iostream>

int main()
{
    // size_t 一般表示内存大小，是32bit的无符号整数
    for(size_t n = 2; n >= 0; n--)
        std::cout << "n = " << n << "  ";
    return 0;
}
