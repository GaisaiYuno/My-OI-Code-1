#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,k,t;
int d[1010],a[1010][10];
int b[1010][10],e[1010];
void input()
{
	scanf("%d%d",&n,&q);
	int c;
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>c>>t;int j=1;
		while(t)
		{
			b[i][j]=t%10;
			t=t/10;
			j++;
		}
	}
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	input();
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++) e[i]=d[i];
	for(int i=1;i<=n;i++)
	{
		k=1;
		while(d[i])
		{
			a[i][k]=d[i]%10;
			d[i]=d[i]/10;
			k++;
		}
		d[i]=k;
	}
	
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++)
		{
			k=1;
			for(int l=1;l<=d[i];l++)
			{
				if(a[j][l]!=b[i][l])
				{
					k=0;break;
				}
			}
			if(k==1)
			{
				cout<<e[j]<<endl;
				break;
			}
		}
		if(k==0) cout<<-1<<endl;
	}
	return 0;
}
