#include <iostream>
#include <climits>
#include "add.h"

int main()
{
    long num1 = 2147483647;
    long num2 = 1;
    long result = 0;

    result = add(num1, num2);

    std::cout << "long int size: " << sizeof(long int) * 8 << " bits" << std::endl;
    std::cout << "long int max: " << LONG_MAX << std::endl;

    std::cout << "The result is " << result << std::endl;

    // std::cout << "add(1, 1) size: " << sizeof(add(1, 1)) * 8 << " bits" << std::endl;
    return 0;
}
