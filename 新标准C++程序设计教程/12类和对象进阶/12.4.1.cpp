#include <iostream>
using namespace std;
class CRectangle{
	private:
		int w,h;
		static int totalArea;
		static int totalNumber;
	public:
		CRectangle(int w_,int h_);
		~CRectangle();
		static void PrintTotal();
};

CRectangle::CRectangle(int w_,int h_){
	w = w_; h = h_;
	totalNumber++;
	totalArea += w * h;
}

CRectangle::~CRectangle(){
	totalNumber--;
	totalArea -= w * h;
}

void CRectangle::PrintTotal(){
	cout << totalNumber << "," << totalArea << endl;
}

int CRectangle::totalNumber = 0;
int CRectangle::totalArea = 0;

int main(){
	CRectangle r1(3,3),r2(2,2);
	CRectangle::PrintTotal();
	r1.PrintTotal();
	CRectangle r3 = new CRectangle;
	delete r1;
	CRectangle::PrintTotal();
	return 0;
}
