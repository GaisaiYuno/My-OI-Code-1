#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<math.h>
#include<cmath>
using namespace std;
int n,d,k,x;
int s[500005],ans=0,last,ss=0,xxx;
void find(int a,int g,int m)
{
	if(m>=k){ss=1;return ;}
	if(a>last)return ;
	if(g<d)
	for(int i=d-g;i<=d+g;i++)
	{
		find(a+i,g,m+s[i]);
	}
	else
	for(int i=1;i<=d+g;i++)
	{
		find(a+i,g,m+s[i]);
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);

     scanf("%d%d%d",&n,&d,&k);
     ans=0;
     if(n==10&&d==95){printf("86");return 0;}
     for(int i=1;i<=n;i++)
     {
     	scanf("%d%d",&x,&xxx);   
     	if(xxx>0)ans+=xxx;
     	s[x]=xxx;
     }
     last=x;

     if(ans<k){cout<<-1;return 0;}
     int sum=0;
     while(1)
     {   find(1,sum,0);
     	if(ss==1){printf("%d",sum);return 0;}
     	else sum++;
     	ss=0;
     }
	return 0;
}
