#include <any>
#include <iostream>
#include <list>
#include <vector>

int main() {
    std::string s("hello");
    int a = 10;
    std::vector<int> v{ 1, 2, 3 };

    std::any any1(s);
    std::any any2(a);
    std::any any3(v);

    std::list<std::any> _list;
    _list.push_back(any1);
    _list.push_back(any2);
    _list.push_back(any3);
    
    for (auto& c : _list) {
        std::cout << c.type().name() << std::endl;
    }

    std::string hello_str = std::any_cast<std::string> (any1);
    std::cout << hello_str << std::endl;

    try {
        int b = std::any_cast<int>(any3);
        std::cout << b << std::endl;
    }
    catch (std::bad_any_cast const &e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
/*
* Out:
* 
* class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
* int
* class std::vector<int,class std::allocator<int> >
* hello
* Bad any_cast
* 
*/
