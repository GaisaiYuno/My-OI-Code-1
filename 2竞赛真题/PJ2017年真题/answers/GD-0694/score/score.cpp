#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,ans;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=a/5;
	b=b/10;
	b=b*3;
	c=c/2;
	ans=a+b+c;
	cout<<ans;
	return 0;
}
