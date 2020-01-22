#include<iostream>
#include<cstdio>
using namespace std;
float a,b,c,n;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	n=a/5+b*0.3+c/2;
	cout<<n<<endl;
	return 0;
}
