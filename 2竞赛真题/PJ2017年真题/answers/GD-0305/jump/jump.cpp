#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	long long a,b,c,i,zj=0,js=0,max=0,a1[5001]={0},b1[5001]={0},cj;
	cin>>a>>b>>c;
	for(i=1;i<=a;i++){
		cin>>a1[i]>>b1[i];
		js+=b1[i];
	}
	if(js<c) cout<<-1;
	else{
		js=0;
		for(i=1;i<=a;i++){
			if(js>c) break;
			cj=a1[i]-a1[i-1];
			if(abs(b-cj)>max) max=abs(b-cj);
			js+=b1[i];
		}
		cout<<max;
	}
	fclose(stdin);
	fclose(stdout);
}

