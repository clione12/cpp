# C++ chap1

- 程序的编译和链接
    - g++ -c -o —std
- 解释hello_world.cpp的基本语法
    - 运算符重载
    - C和C++的输入流和输出流
- preprocess
    
    预处理在编译前执行，相当于执行了替换
    
    - #define
    - #include
- 各种各样的程序
    - code once compiler everywhere
- c++中报错的原因
    - 链接报错
    - 语法错误
    - 运行时错误
- 如何通过命令行和（C++）程序交互
    - arg，*args

QA

- g++ 是什么，g++在mac上编译的文件可以运行在windows或者linux上吗
    - g++ 是gun compiler collection （gcc）的前端工具
    - 不可以，除非使用交叉编译

- 为什么执行hello的时候，需要使用./hello
    - 如果不加./的话，会在环境变量中查找
    - 为了区分，所以要这么做

- 关于环境变量一些技巧
    
    ```bash
    # 查看环境变量
    printenv | grep mysql
    
    # 查看命令在哪里
    which mysql
    
    # 查看命令的path
    command -v mysql
    ```
    

- gcc是什么，gcc可以编译c++文件吗
    - 当然可以，gcc可以编译c和c++，编译c++的时候使用的是g++
    - 如果想编译c，可以使用gc

- python这个语言，为什么可以不编译就运行呢？
    - Python 的“不编译”只是表面上的现象，实际上它在运行时会自动完成从源代码到字节码（pyc）的编译，并通过Python虚拟机（ PVM）解释执行字节码
    - 因此变量的类型是在运行时确认的
    - 下次如果有相同的代码运行，会直接执行pyc文件
    
- g++ 中的-c是什么
    - 是生成目标文件的方式，不执行链接
- 什么是目标文件，什么是链接，c++编译的整体流程是，为什么是这样的流程
    - 目标文件，简单来说就是一个中间文件，包含了一些机器码和占位符
    - 链接，简单来说就是对中间文件中的占位符进行重定位
    - 编译流程为：预处理→编译→汇编→链接
    - 为什么这么做：大型项目中，需要分开编译，这样效率高

- makefile是干啥的
    - 多个文件需要链接的时候会用到，这里不展开

- 可以解释一下c++中cin和cout的原理吗（以cin为例）
    - `cin` 是一个全局的 `std::istream` 对象
    - `cin >> num; // 等价于 cin.operator>>(num)`
    - `cin` 会从输入缓冲区中读取数据，并将其转换为指定变量的类型，这是会进行一些类型判断
- 为啥是std::cin，你如何理解：#inclue<iostream> using namespace std;
    
    ```bash
    # 在#inclue<iostream>的时候 ，实际上是把iostream中的所有的头文件的内容给引入进来了
    
    # iostream.hpp中，有这么个东西
    namespace std {
        class istream;
        class ostream;
        extern istream cin;
        extern ostream cout;
        // 其他相关内容...
    }
    
    # 实际上，using namespace就是引入了整个命名空间，因此我们可以自由地使用cin和cout
    
    # 其实，我们也可以自己写个头文件，然后在头文件中定义namespace，然后通过using直接在代码中使用
    ```