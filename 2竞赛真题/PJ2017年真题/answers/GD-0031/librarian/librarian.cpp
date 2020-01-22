#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,q,bn[1005],len,wt;

bool cmp(int a,int b)
{
	return a<b;
}
void input();
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	input();
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&len,&wt);
		bool out=0;
		for(int j=0;j<n;j++)
		{
			int tmp=bn[j],wn=wt;
			bool flag=1;
			while(wn)
			{
				if(tmp%10!=wn%10)
					flag=0;
				wn=wn/10;
				tmp=tmp/10;
			}
			if(flag)
			{
				printf("%d\n",bn[j]);
				out=1;
				break;
			}
		}
		if(!out) printf("%d\n",-1);
	}
	return 0;
}
void input()
{
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%d",bn+i);
	sort(bn,bn+n,cmp);
	return;
}
