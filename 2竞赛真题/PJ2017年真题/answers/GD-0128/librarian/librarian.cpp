#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<stdlib.h>

using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int i,n,m,x,y,w,e,r[10005]={0},k,j,q=1000000001;
	string a[10005],b;
	cin>>n>>m;
	for(i=1;i<=n;++i)
	cin>>a[i];
	for(i=1;i<=n;++i)
	{
		for(j=0;j<a[i].size();++j)
		r[i]=r[i]*10+a[i][j]-48;
	}
	for(i=1;i<=m;++i)
	{
		cin>>x;cin>>b;w=q;
		for(k=1;k<=n;++k)
		{
			e=a[k].size();y=1;
			if(e>=x) 
			{for(j=x-1;j>=0;--j)
			{
				e--;
				if(b[j]!=a[k][e]) y=-1;
			}}
			else y=-1;
			if(y==1) if(w>r[k]) w=r[k];
		}
		if(w==q) cout<<"-1"<<endl;
		    else cout<<w<<endl;
	}
	return 0;
}
