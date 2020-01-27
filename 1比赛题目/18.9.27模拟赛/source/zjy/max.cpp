#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200005
//Éµ±ÆÕÅ×Ó³½£¬º¦ÎÒ±©0 
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int N,maxx;
int arr[maxn];
int find(int x,int k)
{
	int l=1,r=N,mid,ans=0;
	while(l<=r)
	{
//	cout<<"check: "<<l<<" "<<r<<" "<<mid<<endl;
		mid=l+r>>1;
		if(arr[mid]<=x)
			l=mid+1,ans=arr[mid];
		else
			r=mid-1;
		
	}
//	cout<<"NOTE: "<<x<<" "<<k<<" "<<ans<<endl;
	return ans%k;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	read(N);
	for(int i=1;i<=N;i++)
		read(arr[i]);
	sort(arr+1,arr+1+N);
	for(int i=1;i<=N;i++)
	{
		for(int k=1;arr[i]*k<2*arr[N];k++)
			maxx=max(find(k*arr[i],arr[i]),maxx);
	}
	printf("%d",maxx);
}
