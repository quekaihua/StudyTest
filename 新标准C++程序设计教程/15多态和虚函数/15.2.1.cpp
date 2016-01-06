#include <iostream>
#include <cmath>
using namespace std;
class CShape{
	public:
		virtual double Area(){};
		virtual void PrintInfo(){};
};
class CRectangle:public CShape{
	public:
		int w,h;
		virtual double Area();
		virtual void PrintInfo();
};
class CCircle:public CShape{
	public:
		int r;
		virtual double Area();
		virtual void PrintInfo();
};
class CTriangle:public CShape{
	public:
		int a,b,c;
		virtual double Area();
		virtual void PrintInfo();
};
double CRectangle::Area(){
	return w * h;
}
void CRectangle::PrintInfo(){
	cout << "CRectangle:" << Area() << endl;
}
double CCircle::Area(){
	return 3.14 * r * r;
}
void CCircle::PrintInfo(){
	cout << "CCircle:" << Area() << endl;
}
double CTriangle::Area(){
	double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
void CTriangle::PrintInfo(){
	cout << "CTriangle:" << Area() << endl;
}
CShape *pShapes[100];
int MyCompare(const void *s1,const void *s2){
	CShape **p1 = (CShape **)s1;
	CShape **p2 = (CShape **)s2;
	double a1 = (*p1)->Area();
	double a2 = (*p2)->Area();
	if(a1 < a2)
		return -1;
	else if(a2 < a1)
		return 1;
	else 
		return 0;
}
int main(){
	int i;int n;
	CRectangle *pr;CCircle *pc;CTriangle *pt;
	cin >> n;
	for(i=0;i<n;++i){
		char c;
		cin >> c;
		switch(c){
			case 'R':
				pr = new CRectangle();
				cin >> pr->w >> pr->h;
				pShapes[i] = pr;
				break;
			case 'C':
				pc = new CCircle();
				cin >> pc->r;
				pShapes[i] = pc;
				break;
			case 'T':
			pt = new CTriangle();
			cin >> pt->a >> pt->b >> pt->c;
			pShapes[i] = pt;
			break;
		}
	}
	qsort(pShapes,n,sizeof(CShape *),MyCompare);
	for(i = 0;i<n;++i){
		pShapes[i]->PrintInfo();
		delete pShapes[i];
	}
	
	return 0;
}
