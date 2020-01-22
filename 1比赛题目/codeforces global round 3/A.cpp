#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,c;
long long ans=0;
int main(){
	cin>>a>>b>>c;
	int x=min(a,b);
	ans=(c+x)*2;
	a-=x;
	b-=x; 
	if(a>0||b>0) ans++;
	printf("%I64d\n",ans);
}

