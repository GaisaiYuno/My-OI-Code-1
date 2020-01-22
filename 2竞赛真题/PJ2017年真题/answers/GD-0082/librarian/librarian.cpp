#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
int n,q;
int len;
string need;
int answer[1005]={-1};
struct book{
	string num;
	int len=0; 
}a[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	memset(answer,-1,sizeof(answer));
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num;
		a[i].len=a[i].num.size();
		a[i].len-=1;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>len>>need;
		int j=0,k=0,l=0,num;
		bool flag=true;
		len--;
		for(j=1;j<=n;j++)
		{
			flag=true;
			l=0;
			for(k=a[j].len-len;k<=a[j].len;k++)
			{
				if(a[j].num[k]!=need[l])flag=false;
				l++;
			}
			if(!flag)continue;
			num=0;
			for(k=0;k<=a[j].len;k++)
			{
				num=num*10+a[j].num[k]-'0';
			}
			if(num<answer[i]||answer[i]==-1)
			answer[i]=num;
		}
	}
	for(int i=1;i<=q;i++)
	printf("%d\n",answer[i]);
	return 0;
}
