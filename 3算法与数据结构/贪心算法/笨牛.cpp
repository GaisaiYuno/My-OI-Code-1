//洛谷 笨牛 3056
#include<iostream>
#include<cstring> 
using namespace std;
int main(){
    char a;
	int l=0,ans=0;
	while(cin>>a){
		if(a=='(') l++;//记录左括号 
		else if(a==')'&&l>=1) l--;//用右括号抵消 
		else if(a==')'&&l==0){
			l++;
			ans++;//不平衡 
		}	
	} 
	cout<<ans+l/2;
	return 0;
} 
