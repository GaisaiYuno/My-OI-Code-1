#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
inline void read(double &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
double arr[maxn],N;
bool check(double mid)
{
	double tot=0;
	for(int i=1;i<=N;i++)
	{
		arr[i]-=mid;
		tot+=arr[i];	
	}	
	double sum=arr[2],maxx=arr[2];
	for(int i=3;i<N;i++)
	{
		if(sum+arr[i]<=arr[i])
			sum=arr[i];
		else
			sum+=arr[i];
		maxx=max(maxx,sum);
	}
	for(int i=1;i<=N;i++)
		arr[i]+=mid;
//	cout<<tot<<' '<<maxx<<endl;
	return tot<=maxx;
}
int main()
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	read(N);
	for(int i=1;i<=N;i++)
		read(arr[i]);
	double l=0,r=10000,ans=0,mid;
	while(r-l>0.0001)	
	{
		mid=(l+r)/2;
//		cout<<mid<<" ";
		if(check(mid))
			r=mid,ans=mid;
		else
			l=mid;
	}
	printf("%.3f",ans);
}
