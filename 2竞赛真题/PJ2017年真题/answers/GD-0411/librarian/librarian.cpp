#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct ans
{
	int a[15];
	int num;
	bool check;
}b[1010];
int comp(const ans &n,const ans &m)
{
	if(n.num>m.num) return 0;
	return 1;
}
char s[1005];
int h[1005];
//int a[1010][15];
//int b[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	memset(h,-1,sizeof(h));
	int n,q,x;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int w=0;
		cin>>b[i].num;
		b[i].check=0;
		int k=b[i].num;
		while(k!=0) 
		{
			k/=10;w++;
		}
		for(int j=1;j<=w;j++)
		{
			int y=1;
			for(int u=1;u<=j;u++) y*=10;
			b[i].a[j]=b[i].num%y;
		}
	}
	sort(b+1,b+n+1,comp);
	int len;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&len);
		for(int j=0;j<len;j++) cin>>s[j];
		sscanf(s,"%d",&x);
		for(int j=1;j<=n;j++) 
		{
			if(b[j].check==0)
			{
				if(b[j].a[len]==x) 
				{
					h[i]=b[j].num;b[i].check=1;break;
				}
			}
		}
	}
	for(int i=1;i<q;i++) printf("%d\n",h[i]);
	if(q>1) printf("%d",h[q]);
	fclose(stdin);fclose(stdout);
	return 0;
}
