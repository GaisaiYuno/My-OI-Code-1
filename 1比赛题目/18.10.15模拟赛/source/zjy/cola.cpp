#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
struct node{
	int nex,to;
}edge[maxn];
int head[maxn],tot;
inline void insert(int from,int to)
{
	edge[++tot].nex=head[from];
	head[from]=tot;
	edge[tot].to=to;
}
int N,M,t;
int ans;
void dfs(int x,int step)
{
	//cout<<"NOTE :"<<x<<" "<<step<<endl;
	if(step==t)
	{
		ans+=1;
		return ;
	}
	ans++;
	for(int i=head[x];i;i=edge[i].nex)
		dfs(edge[i].to,step+1);
}
int main()
{
	freopen("cola.in","r",stdin);
	freopen("cola.out","w",stdout);
	int u,v;
	read(N);read(M);
	for(int i=1;i<=M;i++)
	{
		read(u);read(v);
		insert(u,v);
		insert(v,u);
	}
	for(int i=1;i<=N;i++)
		insert(i,i);
	read(t);
	dfs(1,0);
	cout<<ans%2017;
}
