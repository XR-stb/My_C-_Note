```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
using namespace std;

typedef tuple<int,int,int> tiii;

class My_Template{
  //因为我们不能去ostream和istream中去重载 << >> 所以友元函数的作用就来了
	friend ostream & operator << (ostream &out, tiii e);
};

ostream & operator << (ostream &out, tiii e){
	out << get<0>(e) << " "
		<< get<1>(e) << " "
		<< get<2>(e) << "\n";
	return out;
}
int main(){
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<tiii> v(n);
    int a, b, c;
    for(int i = 0; i < n; i++){
    	cin >> a >> b >> c;
    	auto t = make_tuple(a,b,c);
    	v[i] = t;
    }
	sort(v.begin(), v.end(), [&](tiii a, tiii b){
		if(get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
		return get<0>(a) > get<0>(b);
	});
	
	for(auto &e : v){
		cout << get<0>(e) << get<1>(e) << get<2>(e) << endl;
	}
	
		
		
    
	return 0;
}
```
