//��� ��ţ 3056
#include<iostream>
#include<cstring> 
using namespace std;
int main(){
    char a;
	int l=0,ans=0;
	while(cin>>a){
		if(a=='(') l++;//��¼������ 
		else if(a==')'&&l>=1) l--;//�������ŵ��� 
		else if(a==')'&&l==0){
			l++;
			ans++;//��ƽ�� 
		}	
	} 
	cout<<ans+l/2;
	return 0;
} 
