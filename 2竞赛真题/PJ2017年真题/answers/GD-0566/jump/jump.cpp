#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,d,k,g=0,j,anss,t[500005][8],i;
bool ch(int x,int a,int f)
{
	for(int l=1;l<=a;l++)
	{
		int tt=t[x+l][2];
		if(t[x+l][2]>=abs(f)) return 1;
		if(ch(x+l,a,f+tt))return 1;;
    }
	return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i][1],&t[i][2]);
		if(t[i][2]>0)anss+=t[i][2];
	}
	if(anss<k) printf("-1\n");
	anss=0;
	while(1)
	{
		j=0;anss=0;
		bool p=0;
		if(d<=g) i=1;
		else i=d-g;
		while(i<=d+g)
		{
			if(t[j+i][2]<0&&ch(j+i,d+g,t[j+i][2])==1){j+=i;p=1;anss+=t[j][2];continue;}
			if(t[j+i][2]>0){j+=i;p=1;anss+=t[j][2];continue;}
			if(anss>=k){printf("%d\n",g);return 0;}
			i++;
		}
		g++;
	}
	return 0;
}
