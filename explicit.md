# c++ explicit

**explicit**主要用于指明类的**单参构造函数**的是**显示调用**的，而**非隐式调用**。

那么在这里什么是**显示调用**，什么是**隐式调用**呢？

来看一个显式调用的例子

```cpp
#include<iostream>

using namespace std;

class A{
public:
    A(double val) : m_val(val){} //一个参数（单参）的构造函数
    double m_val;
};

int main(){
    A a1(3.14); //显示调用一个参数的构造函数

    cout << "a1.m_val = " << a1.m_val << endl;
    cout << "_________________________________________" << endl; 
    system("pause");
    return 0;
}
```

![image](https://user-images.githubusercontent.com/56108982/168458672-85fbc9e0-7e57-48da-9bc8-eaeacb95a276.png)

大多数情况下，我们通过显示调用来对对象进行赋值，不会有问题

但是由于存在**隐式转换**，下面来看看隐式转换和调用

```cpp
#include<iostream>

using namespace std;

class A{
public:
    A(double val) : m_val(val){} //一个参数（单参）的构造函数
    double m_val;
};

int main(){
    A a1(3.14); //显示调用一个参数的构造函数
    A a2 = 2.56;
    cout << "a1.m_val = " << a1.m_val << endl;
    cout << "a2.m_val = " << a2.m_val << endl;
    cout << "_________________________________________" << endl; 
    system("pause");
    return 0;
}
```

![image](https://user-images.githubusercontent.com/56108982/168458660-48f8a269-8d36-4f7a-810a-4d3894acb97d.png)

上例中，A a2 = 2.56 就进行了一次隐式转换，转换方式为创建一个临时的对象，再进行赋值

```cpp
A temp(2.56);
a2 = temp;
```

explicit关键字可以阻止构造函数的隐式转换，只对：只含有一个参数，或n个参数里面，有n-1个参数是带有默认值的**构造函数**才有效

> error: conversion from 'double' to non-scalar type 'A' requested

![image](https://user-images.githubusercontent.com/56108982/168458654-ddc6febb-4f1b-456f-a69a-dc03b3b6358b.png)

可以看到，在我们添加了explicit关键字后，构造函数就不能再进行隐式转换了















