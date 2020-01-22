#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 300005
#define yep cout<<"yep"<<endl;
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int N,arr[maxn],K;
int st[maxn][25][2];
inline void init()
{
	for(int i=1;i<=N;i++)
	{
		st[i][0][0]=arr[i];
		st[i][0][1]=arr[i];
	}
	for(int k=1;k<=20;k++)
	{
		for(int i=1;i<=N;i++)
		{
			if(i+(1<<(k-1))>=N)	
				break;
			st[i][k][0]=min(st[i][k-1][0],st[i+(1<<(k-1))][k-1][0]);
			st[i][k][1]=max(st[i][k-1][1],st[i+(1<<(k-1))][k-1][1]);
		}
	}
			
}
inline int query(int l,int r,int ty)
{
	int lg=log2(r-l+1);
	if(ty==1)
		return max(st[l][lg][1],st[r-(1<<lg)+1][lg][1]);
	else	
		return min(st[l][lg][0],st[r-(1<<lg)+1][lg][0]);
}
inline bool check(int mid)
{
	for(int i=1;i<=N-mid+1;i++)
		if(query(i,i+mid-1,1)-query(i,i+mid-1,0)<=K)
		{
		//	cout<<mid<<endl;
			return 1;
		}		
	return 0;
}
int main()
{
	freopen("bed.in","r",stdin);
	freopen("bed.out","w",stdout);
	read(N);read(K);
	for(int i=1;i<=N;i++)
		read(arr[i]);
	init();
	int l=1,r=N,mid,ans=1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
			l=mid+1,ans=mid;
		else
			r=mid-1;
	//	cout<<l<<" "<<r<<" "<<mid<<endl;
	}
	printf("%d",ans);
}
