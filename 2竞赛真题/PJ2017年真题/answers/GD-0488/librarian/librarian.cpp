#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int MAXN=1005,INF=1e8+5;
int book[MAXN],wants[MAXN];
int numb[MAXN],numw[MAXN];
int n,q,now,w;
int gets(int now)
{
	int w=0;
	if(now==0)	w=1;
	while(now)
	{
		w++;
		now/=10;
	}	
	return w;
}
void read()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)	
	{
		cin>>book[i];//记录具体 
		numb[i]=gets(book[i]);
	}
	for(int i=1;i<=q;i++)
		cin>>numw[i]>>wants[i];	
}
int getw(int k)
{
	int now2=1;
	for(int i=1;i<=k;i++)	now2*=10;
	return now2;
}
void runs()
{
	for(int i=1;i<=q;i++)
	{
		int ans=INF;
		for(int j=1;j<=n;j++)
		{
			if(numb[j]<numw[i])	continue;//位数 
			int wei=getw(numw[i]);
			int mod=book[j]%wei;
			if(mod==wants[i])	
				ans=min(ans,book[j]);			
		}
		if(ans==INF)	ans=-1;
		cout<<ans<<endl;
	}
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	read();	
	runs();	
	return 0;
}
