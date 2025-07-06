#include <iostream>


using namespace std;

class MyClass {
    public:
        void print() {
            std::cout << this << std::endl;  // 打印当前对象的地址
        }
    };
    
int main(){
    MyClass obj;
    obj.print();  // 等价于 MyClass::print(&obj)
}
