#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 100005
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int N,B;
int arr[maxn];
struct ques{
	int x,y;
	int nex,ahead;
	int num;
	int bo;
}que[maxn];
inline bool cmp1(ques a,ques b)
{
	return a.x<b.x;
}
inline bool cmp2(ques a,ques b)
{
	return a.num<b.num;
}
int head;
inline void solve(int x)
{
	int s=que[x].x,d=que[x].y;
	int p=1;
	while(p<N)
	{
		bool flag=0;
		for(int i=p+d;i>p;i--)
		{
			if(i>=N)
			{
				p=N;
				flag=1;
				break;
			}
			if(arr[i]<=s)
			{
				p=i;
				flag=1;
				break;
			}		
		}
		if(!flag)
		{
			que[x].bo=-1;
			return ;
		}	
	}
	que[x].bo=1;
	for(int i=que[x].nex;i;i=que[i].nex)
	{
		if(que[i].y>=que[x].y)
		{
			que[i].bo=1;
			que[que[i].ahead].nex=que[i].nex;
			que[que[i].nex].ahead=que[i].ahead;
		}
	}
}
int main()
{
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	read(N);read(B);
	for(int i=1;i<=N;i++)
		read(arr[i]);
	for(int i=1;i<=B;i++)
	{
		read(que[i].x);
		read(que[i].y);
		que[i].num=i;
	}
	sort(que+1,que+1+B,cmp1);
	for(int i=1;i<B;i++)
		que[i].nex=i+1;
	for(int i=2;i<=B;i++)	
		que[i].ahead=i-1;
	for(int i=1;i<=B;i++)
		if(que[i].bo==0)
			solve(i);
	sort(que+1,que+1+B,cmp2);
	for(int i=1;i<=B;i++)
	{
		if(que[i].bo==1)
			printf("1\n");
		else	
			printf("0\n");
	}
}
