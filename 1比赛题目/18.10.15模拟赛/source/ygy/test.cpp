#include<iostream>
#include<algorithm>
using namespace std;
int a[]={1,3,4,4,4,5,6,10,15};
int main(){
	int n;
	while(cin>>n){
		cout<<upper_bound(a,a+9,n)-a<<endl;
	}
}
//123812381238123812387777777238238 booster
//123712371237888123781237823782378 annihilator
//123456789012345678901234567890123
