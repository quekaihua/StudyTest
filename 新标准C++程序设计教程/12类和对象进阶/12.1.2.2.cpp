#include <iostream>
using namespace std;
class CTest{
	public:
		CTest(int n){
		}
		CTest(int n,int m){
		}
		CTest(){
		}
};
int main(){
	CTest array1[3] = {1,CTest(1,2)};
	CTest array2[3] = {CTest(2,3),CTest(1,2),1};
	CTest *pArray[3] = {new CTest(4),new CTest(1,2)};
	return 0;
}
