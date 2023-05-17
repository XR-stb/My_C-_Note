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
