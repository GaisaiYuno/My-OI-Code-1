#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a/=10;
	b/=10;
	c/=10;
	a*=2;
	b*=3;
	c*=5;
	d=a+b+c;
	cout<<d;
}
