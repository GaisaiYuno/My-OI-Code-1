#include<iostream>
#include<cstdio>
using namespace std;

 int a,b,c,ans=0;
 
 int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
    a*=0.2;
    //cout<<a;
	b*=0.3;
	if(b!=0)
	b++;
	//cout<<b;
	c*=0.5;
	//cout<<c;
	ans=a+b+c;
    cout<<ans;
	return 0;
}
