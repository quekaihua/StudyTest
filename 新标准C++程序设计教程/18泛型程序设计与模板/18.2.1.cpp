#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Pair
{
public:
	T1 key;
	T2 value;
	Pair(T1 k, T2 v):key(k), value(v) {};
	bool operator < (const Pair<T1, T2> &p) const;
};

template <class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2> &p) const
{
	return key < p.key;
}

int main()
{
	Pair<string, int> student("Tom", 19);
	cout << student.key << " " << student.value << endl;
	Pair<string, int> student2("Tzm", 20);
	cout << (student2 < student) << endl;
	return 0;
}