#include<iostream>
using namespace std;
int a,b,c,ans;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=a*2;
	b=b*3;
	c=c*5;
	ans=a+b+c;
	cout<<ans/10;
}
