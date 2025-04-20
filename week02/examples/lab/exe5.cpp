#include <iostream>
int main()
{
    auto a = 10;
    a = 20.5;
    a += 10.5;
    // 这里是因为，auto是在最开始，类型就已经指定了
    std::cout << a << std::endl;
    return 0;
}