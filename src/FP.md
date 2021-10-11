```cpp
#include <iostream>

using namespace std;

int foo(){
    return 114514;
}

typedef decltype(foo) *fun_ptr;

class fun{
public:
    operator fun_ptr() const{
        return foo;
    }
};

int main() {
   auto ask_ptr = &foo;
   cout<< ask_ptr()<<endl;
   auto & ref = foo;
   cout<<ref()<<endl;
   fun obj;
   cout<<obj()<<endl;
}
```

![image](https://user-images.githubusercontent.com/56108982/136776969-71f211ac-4252-42ef-aeb6-26a0f3e4b505.png)
