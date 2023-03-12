**判断tuple是否为其类型的子集**
```cpp
#include <tuple>
#include <iostream>
#include "print.h"

using namespace std;

template<typename T, typename ...Types>
constexpr int find_type_index(int sn) {
	int index = 0;
	bool found = false;
	auto helper = [&](auto current_type) constexpr {
		if constexpr (is_same_v<T, decltype(current_type)>) {
			if (sn < index) {
				found = true;
				return;
			}
		}
		if (!found) index++;
	};
	(helper(Types{}), ...);
	return found ? index : -1;
}

template<typename ...SubArgs, typename ...SuperArgs>
constexpr bool isSubSetOf(const tuple<SubArgs...>& sub, const tuple<SuperArgs...>& super) {
	int sn = -1;
	bool found = true;
	auto helper = [&](auto current_type) constexpr {
		if(find_type_index<decltype(current_type), SuperArgs...>(sn) == -1) {
			found = false;
			return;
		}
		else {
			sn = find_type_index<decltype(current_type), SuperArgs...>(sn);
		}
	};
	(helper(SubArgs{}), ...);
	return found;
}

int main() {
	tuple<int, double, char> a = { 1, 2.0, 'c' };
	tuple<double, char> b = { 2.0, 'c' }, c = { 1.0, 'c' };
	tuple<char, double> e = {'c', 1.0};
	tuple<string> d = { "hello" };
	print("{}\n", isSubSetOf(b, a));//true
	print("{}\n", isSubSetOf(e, a));//false
	print("{}\n", isSubSetOf(c, b));//true
	print("{}\n", isSubSetOf(a, d));//false
}
```
