#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a, b;
    double c, d;
    a = 19.99 + 21.99;
    b = (int)19.99 + (int)21.99;
    c = 23 / 8;
    d = 23 / 8.0;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    // 这里的原因是，隐式转为int，会直接截断，而不是四舍五入
    cout << fixed <<setprecision(20);
    cout << a << endl;
    // cout << "0/0= " << 0/0 << endl;
    return 0;
}
