![image](https://user-images.githubusercontent.com/56108982/142633543-11eae8f2-d6a9-48a2-b32f-7655d042f5b0.png)
```cpp
#include <malloc.h>
#include <iostream>
#include <thread>

using namespace std;

void foo() {
    cout << "foo thread " << this_thread::get_id() << endl;
    for (int i = 0; i < 5; i++) {
        this_thread::sleep_for(1s);
    }
    cout << "end foo thread " << endl;
}

int main() {
    cout << "main thread " << this_thread::get_id() << endl;
    thread th(foo);
    cout << "begin wait sub thread " << endl;
    th.join();
    cout << "end sub thread " << this_thread::get_id() << endl;
    return 0;
}
```
