//线性结构
template <class T>
class List{
	void clear();
	bool isEmpty();
	bool append(T value);
	bool insert(int p,T value);
	bool del(int p);
	T getValue(int p);
	T setValue(int p,T value);
}; 
