#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	int aa=a/5,bb=b*3/10,cc=c/2;
	cout<<aa+bb+cc;
	return 0;
}
