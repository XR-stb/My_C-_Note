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
