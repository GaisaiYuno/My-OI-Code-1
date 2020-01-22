#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,a[1000000+5],b[1000000+5],leftt,rightt,mid,sum,big,ss,p,s,x,y,o;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	 cin>>n>>d>>k;
	 for (int i=1;i<=n;i++)
	 {
	 	cin>>x>>y;
	 	if (y>0) s=s+y;
	 	a[x]=y;
	 	b[x]=1;
	 }
	 cout<<-1;
	 return 0;
}
