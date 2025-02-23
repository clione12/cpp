#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a = 56789;
    int b = 56789;
    cout << std::hex << a << endl;
    int c = a * b;
    cout << std::hex << c << endl;

    cout << "c = " << c << endl;

    unsigned int c1 = a * b; //danger operation
    cout << "c1 = " << c1 << endl;
    return 0;
}
