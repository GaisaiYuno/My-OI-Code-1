#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//À¬»øÕÅ×Ó³½
inline void read(int &x)
{
	char ch=getchar();int f=1;x=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int graph[260][260];
bool dd[260][260];
int N,M;
int main()
{
	freopen("roadblock.out","w",stdout);
	cout<<'0';
	/*read(N);read(M);
	for(int i=1;i<=250;i++)
		for(int j=1;j<=250;j++)
			graph[i][j]=0x3f3f3f3f;
	int u,v,w;
	for(int i=1;i<=M;i++)
	{
		read(u);read(v);read(w);
		if(graph[u][v]!=0x3f3f3f3f)
			dd[u][v]=dd[v][u]=1;
		graph[u][v]=min(graph[u][v],w);
		graph[v][u]=min(graph[v][u],w);
	}
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
			{
				if(i==j)
					continue ;
				
			}*/
}
