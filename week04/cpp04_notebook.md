# cpp04_notebook

## 数组

- 数组

  - 是固定大小的
  - 需要提前初始化

- len是变量的数组

  - num[len] 可以是变量
  - 在编译的时候确定数组大小 sizeof(num)
  - 早期的编译器通不过

- 未知长度的数组 array[]

  - 根据初始化决定
  - 用作函数参数，数组指针表示地址

- 数组的赋值

  - **array 只是表示数组的地址**
  - 需要逐个赋值
  - 小心越界（c++中，数组不是一个类，没有长度的说法，因此不会检查越界，有可能访问甚至修改数组外的内存，比如通过-1）
    - 好处：效率高，不用检查越界
    - 缺点：容易发生致命的问题

- 二维数组

  - 定义和赋值

  ```bash
  int mat[2][3] = {{1,2,3},{1,2,3}}
  ```

  - 作为函数参数

    一维的内存，因此要知道第二个维度的具体的大小，编译器才能计算地址

  ```bash
  void init_array(float arr[][3])
  ```

- const 数组

  - 值不可更改
  - 可用于函数参数中

## 字符串

- array style string

  - 注意，char [12] 是以`\0`结尾的，因此要多一个元素

  - 更方便的定义方式为

    ```c
    char name[] = "hello world"
    char16_t s16[] = u"UTF-16字符串";
    char32_t s32[] = U"UTF-32字符串";
    ```

- `cstring` 中的函数

  - `strcopy` `strncopy` 进行数组赋值，性能更好
  - `strcat` `strncat` 性能更好

- string class

  - 是一个类，但是还是会可能越界
  - 可以当做数组一样访问
  - 有长度可以访问到.length()
  - 重载了+运算符

**QA**

- **wchar_t，char16_t，char32_t分别是什么，有什么作用？**
  - wchar_t 一般用于windows平台
  - char16_t 是UTF-16标准的编码规则覆盖的字符（unicode）
  - char32_t 是UTF-32标准的编码规则覆盖的字符（unicode），覆盖了所有的..
  - 一般的char是基于ascall标准的

## struct, union, enum

**struct**

- 注意，c和cpp中的写法不一样，cpp里不用加入struct的tag；这里的本质原因是，在c++里面，struct本质上和class没有区别，也可以加入类
- 数据pading，这里非常重要，读取的每个变量，地址都应该是4的倍数，不够的pading

**union**

- union中所有的成员共享一个内存
- 即相同的内存，可以有不同的表达形式
- 比如ip地址，32位 = 4 *8 位的数组，可以表达为两种形式

**enum**

- enum本身会创造类型
- enum的值类似 const，不可以加减

**QA**

- struct 在c和cpp中的用法有什么不同
  - **C 的 `struct` 是纯数据结构**，C++ 的 `struct` 是轻量级 `class`
  - **C++ 中 `struct` 和 `class` 的默认访问权限不同**
  - **C 必须用 `struct` 关键字声明变量**，C++ 可省略
  - **C++用 `struct` 表示数据集合**，用 `class` 表示具有行为的对象

## typedef

- 用来定义别名

- 在实际使用中，根据不同的数据模型，定义统一的类型关键词

  ```cpp
  typedef int w_char t
  
  typedef long w_char t
  ```

- size_t 类型，其实是通过typedef定义的别名，其最大最小值通过宏定义