#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <ctime>
#include <utility>
using namespace std;

template <typename V>
vector<V> operator* (vector<V>& a, vector<V>& b);

template <typename P_first, typename P_second>
pair<P_first, P_second> operator* (pair<P_first, P_second>&  a, pair<P_first, P_second>&  b);

template <typename M_first, typename M_second>
map<M_first, M_second> operator* (map<M_first, M_second>&  a, map<M_first, M_second>&  b);

template <typename T> 
T Sqr(T x);

template <typename V>
vector<V> operator* (vector<V>& a, vector<V>& b) {
	vector<V> c(a.size());
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); ++i) {
			c[i] = a[i] * b[i];
		}
	}
	return c;
}

template <typename P_first, typename P_second>
pair<P_first, P_second> operator* (pair<P_first, P_second>&  a, pair<P_first, P_second>&  b) {
	pair<P_first, P_second> c;
	c.first = a.first * b.first;
	c.second = a.second * b.second;
	return c;
}

template <typename M_first, typename M_second>
map<M_first, M_second> operator* (map<M_first, M_second>&  a, map<M_first, M_second>&  b) {
	map<M_first, M_second> c = a;
	for (auto& c_ : c) {
		c_.second = c_.second * b[c_.first];
	}
	return c;
}

template <typename T> // ключевое слово для объявления типа T
T Sqr(T x) {
	T y = x * x;
	return y; // нам нужно, чтобы элемент x поддерживал операцию умножения
}


int main() {
	vector<map<char, pair<float, int>>> monster = { { {'a', { 5.9, 1 }}, { 'b', { 4.9, 1 } }}, { {'c', { 3.9, 2 }}, { 'b', { 5.9, 2 } } } };
	auto result = Sqr(monster);

	return 0;
}
