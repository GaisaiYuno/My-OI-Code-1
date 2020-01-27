//escape
#include<iostream>
#include<cstdio>
using namespace std;
long long m,s,t;
int r1=0,r2=0;
int main(){
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	cin>>m>>s>>t;
	for(int i=1;i<=t;i++){
		r1+=17;
		if(m>=10){
			m-=10;
			r2+=60;
		}
		else if(m<10) m+=4;
		if(r1<r2) r1=r2;
		if(r1>=s){
			cout<<"Yes"<<endl<<i;
			return 0;
		}
	}
	cout<<"No"<<endl<<r1;
	return 0;
} 

