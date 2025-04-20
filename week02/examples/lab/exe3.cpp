#include <iostream>
#include <iomanip>
#include <typeinfo>
using namespace std;
int main() 
{
    cout << fixed;
    float f1 = 1.0f;
    cout<<"f1 = "<<f1<<endl;
    
    float a = 0.1f;
    float f2 = a+a+a+a+a+a+a+a+a+a;
    cout<<"f2 = "<<f2<<endl;
    

    if(f1 == f2)
        cout << "f1 = f2" << endl;
    else
        cout << "f1 != f2" << endl;

    // 这里是因为误差累计，f1和f2实际的二进制表示是不同的
    cout << fixed <<setprecision(20);
    cout << f1 << endl;
    cout << f2 << endl;
    
    cout << a << endl;
    cout << a * 10 << endl;
    cout << typeid(a*10).name() << endl;

    // 这里是因为编译器优化
    // 在进行乘法的时候，会转为双精度运算，然后再转为单精度，此时已经被舍入过了
    bool t = a * 10 == f1;
    cout << t << endl;
    return 0;
}
