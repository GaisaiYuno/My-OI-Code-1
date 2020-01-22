#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,ans;
	cin>>a>>b>>c;
	ans=2*a+3*b+5*c;
	cout<<ans/10;
	return 0;
}
