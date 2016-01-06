#include <iostream>
using namespace std;
class CBug{
	int legNum,color;
	public:
		CBug(int ln,int cl):legNum(ln),color(cl){
			cout << "CBug Constructor" << endl;
		};
		~CBug(){
			cout << "CBug Destructor" << endl;
		}
		void PrintInfo(){
			cout << legNum << "," << color << endl;
		}
};
class CFlyingBug:public CBug{
		int wingNum;
	public:
		CFlyingBug(int ln,int cl,int wn):CBug(ln,cl),wingNum(wn){
			cout << "CFlyingBug Constructor" << endl;
		}
		~CFlyingBug(){
			cout << "CFlyingBug Destructot" << endl;
		}
};
int main(){
	CFlyingBug fb(2,3,4);
	fb.PrintInfo();	
	return 0;
}
