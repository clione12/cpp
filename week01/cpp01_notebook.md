# cpp01_notebook

- 程序的编译和链接
  - g++ 的各种选项
- 解释hello_world.cpp的基本语法
  - 运算符重载
  - C和C++的输入流和输出流
- preprocess
  - 包含了哪些动作
- 各种各样的程序
  - cpp: code once compiler everywhere
- c++中报错的原因
  - 编译错误：一般是语法问题，检查源代码即可
  - 链接报错
  - 运行时错误
- 如何通过命令行和（C++）程序交互
  - arg，*args

## QA

- **g++ 是什么，g++在mac上编译的文件可以运行在windows或者linux上吗**

  - g++ 是gun compiler collection （gcc）的前端工具
  - 不可以，除非使用交叉编译

- **为什么执行hello的时候，需要使用./hello**

  - 如果不加./的话，会在环境变量中查找
  - 为了区分，所以要这么做

- **关于环境变量一些技巧**

  ```bash
  # 查看环境变量
  printenv | grep mysql
  
  # 查看命令在哪里
  which mysql
  
  # 查看命令的path
  command -v mysql
  ```

- **gcc是什么，gcc可以编译c++文件吗**

  - 当然可以，gcc可以编译c和c++，编译c++的时候使用的是g++
  - 如果想编译c，可以使用gc

- **python这个语言，为什么可以不编译就运行呢？**

  - Python 的“不编译”只是表面上的现象，实际上它在运行时会自动完成从源代码到字节码（pyc）的编译，并通过Python虚拟机（ PVM）解释执行字节码
  - 变量的类型是在运行时确认的
  - 下次如果有相同的代码运行，会直接执行pyc文件
  - 对cpython有兴趣，可以看b站 [up](https://space.bilibili.com/245645656) 的视频，以后有机会去读下cpython的源码

- **g++ 中的-c是什么**

  - 是生成目标文件的方式，不执行链接

- **在执行g++的时候，总体来说，关键步骤有哪些？生成的中间文件有哪些？分别包含了哪些内容？**

  - 总体编译流程为：预处理→编译→汇编→链接

    1. **预处理（Preprocessing）**：处理源代码中的预处理指令（如 `#include`, `#define`, `#ifdef` 等），展开宏定义，合并头文件内容。

       ```bash
       # -E 选项表示仅执行预处理。
       # 输出文件通常为 .ii（C++ 预处理后文件）或 .i（C 预处理后文件）。
       g++ -E source.cpp -o source.ii    
       ```

    2. **编译（Compilation）**：将预处理后的代码转换为汇编代码（针对目标平台的低级指令）。

       ```bash
       # -S 选项表示生成汇编代码。
       g++ -S source.ii -o source.s
       ```

    3. **汇编（Assembly）：**将汇编代码转换为机器码（二进制目标文件）。

       ```bash
       # -c 选项表示编译但不链接。
       g++ -c source.s -o source.o
       ```

    4. **链接（Linking）：**将多个目标文件（`.o`）和库文件合并为最终的可执行文件或库。

       ```bash
       g++ source.o -o executable
       ```

- **`#pragma once` 是什么？**

  是现代 C/C++ 项目中防止头文件重复包含的首选方式。但在需要兼容极端环境时，仍需了解传统的 `#ifndef` 方法。一般来说，我们在头文件中加入`#pragma once`，有些情况需要混合使用

  混合使用为：

  ```cpp
  #pragma once
  #ifndef MATH_UTILS_HPP
  #define MATH_UTILS_HPP
  // 头文件内容...
  #endif
  ```

- **什么是增量编译？**

  - 增量编译就是说，每个文件分开编译，最后执行链接，这样做的好处是，在大型项目中，我们无需重复编译已有的内容。

  - 在cmake中，会自动检测，一个cpp文件及其头文件hpp，是否有变化，如果没有变化，是不会执行编译的过程的，只会在最后执行链接

    ```bash
    # 生成构建系统（例如 Makefile）
    mkdir build && cd build
    cmake ..
    
    # 首次编译（全量编译）
    make
    
    # 后续修改文件后，重新编译（自动增量编译）
    make
    
    ```

- **什么是汇编语言？汇编语言和机器码之前有什么关系？**

  - 汇编语言是机器码的文本表示，一般是来说，汇编代码和机器码是一一映射关系
  - 机器码又可以叫做`机器指令`，不同的CPU的指令集是不同的，比如arm指令集和x86指令集
  - 机器码和汇编码之间，可以汇编码可以通过**`汇编器`** （Assembler）转为机器码**，**反之通过**`反汇编器`（Disassembler）**可还原为汇编代码。

- **什么是汇编优化、指令重排？**

  - 汇编优化：通过改写汇编代码，使其更高效（减少指令数、提高缓存命中率、减少分支预测错误等）。可以通过手动优化（手动改汇编代码）or编译器优化。
  - 指令重排：在不改变程序语义的前提下，重新排列指令顺序以利用CPU的**流水线**和**乱序执行**（Out-of-Order Execution）特性，提高并行度。包括硬件级重排和编译器级重排。

- **Makefile是干啥的**

  - Makefile是一个文本文件，用于定义项目中的编译规则和依赖关系

  - 可以在有makefile的目录下执行make

    ```cpp
    make target_name
    make clean
    ```

  - 后面最常用的是cmake，这个工具能根据**`CMakeLists.txt`**生成`Makefile`

    ```cpp
    mkdir build && cd build
    cmake ..
    make
    ```

- **可以解释一下c++中cin和cout的原理吗（以cin为例）**

  - `cin` 是一个全局的 `std::istream` 对象
  - `cin >> num; // 等价于 cin.operator>>(num)`
  - `cin` 会从输入缓冲区中读取数据，并将其转换为指定变量的类型，这是会进行一些类型判断

- **为啥是`std::cin`，如何理解：`#inclue<iostream> using namespace std;`**

  - namespace是为了避免命名重复设置的机制
  - using name space是使用某种命名空间，可以直接使用命名空间中的对象，但是一般不建议这么做（类比下python的库函数使用）

  ```bash
  # 在#inclue<iostream>的时候 ，实际上是把iostream中的所有的头文件的内容给引入进来了
  
  # iostream.hpp中，有这么个东西
  namespace std {
      class istream;
      class ostream;
      extern istream cin;
      extern ostream cout;
      ...
  }
  
  # 实际上，using namespace就是引入了整个命名空间，因此我们可以自由地使用cin和cout
  # 其中，extern表示cin的实际定义位于标准库的某个编译单元（如.cpp文件）中，当前代码只是引用它。
  
  # 其实，我们也可以自己写个头文件，然后在头文件中定义namespace，然后通过using namespace直接在代码中使用
  ```