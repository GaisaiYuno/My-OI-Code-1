#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500005
using namespace std;
//张子辰真他妈素质 
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int Q,top;
double maxx,mean,arr[maxn],s;
long long sum[maxn];
double find(int x)
{
	double minn=double(sum[1]+x)/2;
	for(int i=2;i<top;i++)
	{
		double m=double(sum[i]+x)/double(i+1);
		//cout<<"NOTE: "<<i<<" "<<m<<endl;
		if(m>=minn)
			return minn;
		else
			minn=m;
	}
}
int main()
{
	freopen("nmax.in","r",stdin);
	freopen("nmax.out","w",stdout);
	read(Q);
	int op,x;
	while(Q--)
	{
		read(op);
		if(op==1)
		{
			read(x);
			sum[++top]=sum[top-1]+x;
			arr[top]=x;
			mean=find(x);
			maxx=max(maxx,x-mean);
			//cout<<"NOTE: "<<x<<" "<<mean<<" "<<maxx<<endl;
		}
		else
			printf("%.10f\n",maxx);
	}
}
