#include <iostream>

using namespace std;

class CRectangle
{
	public:
		int w, h;
		void Init(int w_, int h_);
		int area();
		int perimeter();
};

void CRectangle::Init(int w_, int h_)
{
	w = w_;
	h = h_;
}

int CRectangle::area()
{
	return w * h;
}

int CRectangle::perimeter()
{
	return 2 * (w + h);
}

int main()
{
	int w, h;
	CRectangle r;
	cin >> w >> h;
	r.Init(w, h);
	cout << "It's area is " << r.area() << endl;
	cout << "It's perimeter is " << r.perimeter() << endl;
	cout << sizeof(CRectangle) << endl;
	return 0;
}