# include <iostream>
# include <iomanip>
# include <cstdio>


int main(){
    float a = 0.1f;
    float b = 0.2f;
    float c = 0.3f;
    
    // cpp style
    std::cout << std::fixed << std::setprecision(2);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    // c style
    printf("%.2f\n", a);
    printf("%.2f\n", b);
    printf("%.2f\n", c);
}