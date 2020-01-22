#include<iostream>
#include<cstdio>
using namespace std;
int x,save,now;
int main(){
	//freopen("save.in","r",stdin);
	//freopen("save.out","w",stdout);
	save=0;
	for(int i=1;i<=12;i++){
		cin>>x;
		if(now+300<x){
			cout<<-i;
			return 0;
		}
		if(now+300-x>=100){
			int t=now+300-x;
			save+=(t/100)*100;
			now=t-(t/100)*100;
		}
		else now+=300-x;
	}
	cout<<save/5*6+now;
	return 0;
}
