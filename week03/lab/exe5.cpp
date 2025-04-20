#include <iostream>
using namespace std;
int main()
{
    // 常见错误：未初始化的变量
    int n,fa;
    do{
        fa *= n;
        n++;
    }while(n <= 10);
    cout << "fa = " << fa << endl;
    return 0;
}