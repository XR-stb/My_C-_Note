#### 1.使用异步加速计算
```cpp
#include<iostream>
#include<chrono>
#include<future>
#define END auto end = chrono::steady_clock::now(); \
            auto dist = chrono::duration<double>(end - start); \
            cout << "程序总用时: " << dist.count() << " s " << endl; 

using namespace std;

typedef uint64_t ResType;

const ResType N = 10'0000'0000;

ResType calc_1(){
    ResType sum = 0;
    for(int i = 1; i <= N; i++){
        sum = i;
    }
    return sum;
}

ResType calc_2(){
    ResType sum = 0;
    for(int i = 1; i <= N; i++){
        sum = i;
    }
    return sum;
}


int main(){
    auto start = chrono::steady_clock::now();
    // calc_1();
    // calc_2();
    // use_time = 3.3s

    future<ResType> future_1 = async(calc_1);
    future<ResType> future_2 = async(calc_2);

    ResType result = future_1.get() + future_2.get();
    // async use_time = 1.7 to 1.8

    END;
    system("pause");
    return 0;
}
```
#### 2.异步的顺序
```cpp

#include<iostream>
#include<chrono>
#include<future>
#define END auto end = chrono::steady_clock::now(); \
            auto dist = chrono::duration<double>(end - start); \
            cout << "程序总用时: " << dist.count() << " s " << endl; 

using namespace std;

typedef void ResType;

const int cnt = 100;

ResType output(string s){
    for(int i = 0; i < cnt; i++){
        cout << s << endl;
        cout.flush();//flush buffer
    }
}



int main(){
    auto start = chrono::steady_clock::now();

    future<ResType> future_1 = async(std::launch::async, output, "hello"s); //异步求值
    future<ResType> future_2 = async(std::launch::deferred, output, "wo wo wo"s); //惰性求值

    output("wait me!");

    future_1.get();
    future_2.get();

    END;
    system("pause");
    return 0;
}
```
#### 3.异步过程中的异常
```cpp

#include<iostream>
#include<chrono>
#include<future>
#define END auto end = chrono::steady_clock::now(); \
            auto dist = chrono::duration<double>(end - start); \
            cout << "程序总用时: " << dist.count() << " s " << endl; 

using namespace std;

typedef int ResType;

ResType throw_int(){
    throw 1;
}



int main(){
    auto start = chrono::steady_clock::now();

    try{
        thread th(throw_int);
        th.join(); // wait thread end
    }catch(const std::exception& e){ //c++中无法跨线程捕捉异常，所以程序会直接退出
        std::cerr << e.what() << '\n';
    }
    
    END;
    system("pause");
    return 0;
}
```
当然也是有办法可以捕捉的
```cpp

#include<iostream>
#include<chrono>
#include<future>
#define END auto end = chrono::steady_clock::now(); \
            auto dist = chrono::duration<double>(end - start); \
            cout << "程序总用时: " << dist.count() << " s " << endl; 

using namespace std;

typedef int ResType;

ResType throw_int(){
    throw 1;
}



int main(){
    auto start = chrono::steady_clock::now();

    auto f = async(throw_int);
    try{
        f.get();
    }catch(int e){
        cout << e << endl;
    }
    
    END;
    system("pause");
    return 0;
}
```
