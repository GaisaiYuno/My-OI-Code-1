#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
int a[10][1100],p[10];
int iu(int x)
{
	int uu=0;
	while(x>0)
	{
		x/=10;
		uu++;
	}
	return uu;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	p[1]=10;
	p[0]=1;
	for(int i=1;i<=8;i++) p[i]=p[i-1]*10;
	int n,T,t,x,op,y,mmax=0;
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		op=iu(x);
		if(mmax<op) mmax=op;
		a[op][++a[op][0]]=x;
	}
	for(int k=1;k<=8;k++)
		for(int i=1;i<=a[k][0];i++)
			for(int j=i+1;j<=a[k][0];j++)
				if(a[k][i]>a[k][j])
				{
					t=a[k][i];a[k][i]=a[k][j];a[k][j]=t;
				}
	bool bk;
	while(T--)
	{
		scanf("%d%d",&x,&y);
		bk=false;
		for(int k=x;k<=mmax;k++)
		{
			for(int i=1;i<=a[k][0];i++)
			{
				if(a[k][i]%(p[x])==y)
				{
					printf("%d\n",a[k][i]);
					bk=true;
					break;
				}
			}		
			if(bk==true) break;
		}	
		if(bk==false) printf("-1\n");
	}
	return 0;
}
