## 运算符重载

**函数重载（回顾）**

- 相同函数名，不同参数列表（类型或数量）

为什么要重载？

- 更直观，更好用
- 一种常用的机制，你会在很多代码中看到，所以要了解这个机制

**运算符重载**

- 参考下面的形式
- 注意，是否使用引用，根据是否是新的对象，以及对象拷贝

```cpp
    MyTime operator+(int m) const
    {
        MyTime sum;
        sum.minutes = this->minutes + m;
        sum.hours = this->hours;
        sum.hours +=  sum.minutes / 60;
        sum.minutes %= 60;
        return sum;
    }
    MyTime & operator+=(int m) 
    {
        this->minutes += m;
        this->hours +=  this->minutes / 60;
        this->minutes %= 60;
        return *this;
    }
```

**友元函数(friend function)**

- 如果想要操作int+Mytime，或者cout<<mytime 这种，我们不可能去修改int/cout的定义，因此可以使用友元函数，来定义运算符重载
- friend只是个装饰符号，我们只是写在类里面而已
- 这里返回ostream的引用的原因是
    - 我们需要链式调用，所以需要返回std::ostream对象，比如`cout<<t1<<endl`

```cpp
    friend MyTime operator+(int m, const MyTime & t)
    {
        return t + m;
    }    
    
    friend std::ostream & operator<<(std::ostream & os, const MyTime & t)
    {
        std::string str = std::to_string(t.hours) + " hours and " 
                        + std::to_string(t.minutes) + " minutes.";
        os << str;
        return os;
    }
    friend std::istream & operator>>(std::istream & is, MyTime & t)
    {
        is >> t.hours >> t.minutes;
        t.hours +=  t.minutes / 60;
        t.minutes %= 60;
        return is;
    }
```

## 类型转换

c++11标准，支持explicit类型转换

注意没有返回值，只有函数名

因此呢，我们尽量使用explicit这种方式，否则会很容易看不懂吧

```cpp
    //implicit conversion
    operator int() const
    {
        std::cout << "operator int()" << std::endl;
        return this->hours * 60 + this->minutes;
    }
    
    //explicit conversion
    explicit operator float() const
    {
        std::cout << "explicit operator float()" << std::endl;
        return float(this->hours * 60 + this->minutes);
    }
```

另外一个有趣的东西，= 也是运算符，因此也可以重载的，这个时候要和构造函数区分开

```cpp

MyTime & operator=(int m)
    {
        std::cout << "operator=(int)" << std::endl;
        this->hours = 0;
        this->minutes = m;
        this->hours =  this->minutes / 60;
        this->minutes %= 60;
        return *this;
    }
```

```cpp
MyTime t = 30 // 构造函数

MyTime m
m = 100 // 运算符冲澡
```

## 自增运算符

```cpp
// prefix increment    
    MyTime& operator++()
    {
        this->minutes++;
        this->hours += this->minutes / 60;
        this->minutes = this->minutes % 60;
        return *this; 
    }
 
    // postfix increment
    MyTime operator++(int)
    {
        MyTime old = *this; // keep the old value
        operator++();  // prefix increment
        return old; 
    }
```

- 前置自增，返回的是++后的值
- 后置自增，返回的是++前的值
- 这里用int 和返回值来区分了，可以理解为编译器的flag