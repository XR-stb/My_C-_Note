**关键词** value_type的作用 实现一个返回容器数据的模板

考虑设计一个函数，返回容器的一个值
那肯定要是要模板了，不过这个函数的返回类型怎么确定，这里可能就要犯困了
这时，在我们的类模板里面实现一个value_type,他的功能就体现出来了


```cpp
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class A {
public :
    typedef  T value_type;
    typename value_type fun();
};

template<typename T>
typename T::value_type printContainerValue(T container) {
    for (auto& e : container) {
        cout << e << " ";
    }
    cout << endl;
    return *container.begin();
}

int main()
{
    vector<int> v = { 2,4,5,7,4,3 };
    cout << printContainerValue(v);
    return 0;
}
```
![image](https://user-images.githubusercontent.com/56108982/146854414-c06f3cc6-392e-42e3-a6bd-8ff0564b63d3.png)
