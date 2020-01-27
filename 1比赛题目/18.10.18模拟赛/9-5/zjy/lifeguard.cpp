#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cstring> 
#define maxn 100005
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int N,K;
int l[maxn],r[maxn],arr[maxn<<1],num[maxn<<1];
int ans=0;
struct node{
	bool a[maxn];
	int val;
	void cal()
	{
		memset(num,0,sizeof(num));
		for(int i=1;i<=N;i++)
			for(int j=l[i];j<=r[i];j++)
				num[j]++;
		for(int i=1;i<=2*N;i++)
			if(num[i])
				val++;
		if(val>ans)
			ans=val;
	}
};
node getnew()
{
	node p;
	for(int i=1;i<=2*N;i++)
		p.a[i]=0;
	for(int i=1;i<=K;i++)
	{
		int s=(rand()*rand())%N+1;
		//cout<<i<<" "<<s<<endl;
		//system("pause");
		if(p.a[s]){
			continue ;
		}
		p.a[s]=1;
	}
	p.cal();
}
const int T=100;
node p[101];
int main()
{
	freopen("lifeguard.in","r",stdin);
	freopen("lifeguard.out","w",stdout); 
	srand(time(NULL));
	read(N);read(K);
	for(int i=1;i<=N;i++)
	{
		read(l[i]);
		read(r[i]);
		arr[i]=l[i];
		arr[i+N]=r[i];
	}
	sort(arr+1,arr+2*N+1);
	for(int i=1;i<=N;i++)
	{
		l[i]=lower_bound(arr+1,arr+2*N+1,l[i])-arr;
		r[i]=lower_bound(arr+1,arr+2*N+1,r[i])-arr;
		//cout<<"note "<<i<<" "<<l[i]<<" "<<r[i]<<endl;
	}
	for(int i=1;i<=T;i++)
		p[i]=getnew();
	cout<<ans;
} 
