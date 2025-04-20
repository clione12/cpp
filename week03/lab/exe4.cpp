#include <iostream>
using namespace std;
int main()
{
    int n = 1000;
    int sum;
    // 给n就是死循环了
    while(sum >0){
        sum += n;
        cout << "n = " << n << "  ";
        cout << "sum = " << sum << "  ";
    }
    return 0;
}
