#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,d,k,x[10000],s[10000],a[10000],su=0;
bool b[10000];
void jump(int d,int s)
{
	for(int g=1;;g++)
	{
		for(int i=1;i<=d+g;i++)
		{
			if(d>n) 
			{
				cout<<"-1"; return;
			}
			if(s>=k)
			{
				cout<<g; return;
			}
			if(a[d+i])
			jump(d+i,s+a[d+i]);
		}
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>s[i];
		a[x[i]]=s[i];
		if(s[i]>0) su+=s[i];
	}
	if( (su<k) ||
	    ( (su==0)&&(k>0) ) ) { cout<<"-1"; return 0; }
	else
	 jump(0,0);
	return 0;
}
