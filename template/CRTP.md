### CRTP(curious recurring template pattern)
是一种c++的设计模式，精巧地结合了继承和模板编程的技术。  
可以用来给C++中的类提供额外功能、实现静态多态等。

```cpp
#include <iostream>

template<class T>
struct Base{
    void name(){
        (static_cast<T*>(this))->impl();
    }
};

struct A : public Base<A> {
    void impl(){
        std::cout << "A::impl\n";
    }
};

struct B : public Base<B> {
    void impl(){
        std::cout << "B::impl\n";
    }
};

int main() {
    Base<A> baseA; baseA.name();
    Base<B> baseB; baseB.name();

    A a; a.name();
    B b; b.name();
}
```
output:
```
A::impl
B::impl
A::impl
B::impl
```

可以看到，通过模板和继承，AB得到了不属于他们的力量

```cpp
#include <iostream>
#include <string_view>

template<class T>
struct Base{
    void getClassName(){
        std::string_view className = typeid(T).name();
        std::cout << className.substr(1) << "\n";
    }
};

struct A : public Base<A> {};

struct B : public Base<B> {};

int main() {
    A a; a.getClassName();
    B b; b.getClassName();
}
```
output:
```
A
B
```
