#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#define maxn 255
#define INF 0x7fffffff
using namespace std;
int d[maxn];
int L[maxn][maxn];
vector<int>M[maxn];
struct ss{
	int from,to,len;
	ss(){from=to=len=0;}
	ss(int a,int b,int c){from=a,to=b,len=c;}
	friend bool operator<(ss a,ss b){
		return a.len>b.len;
	}
};
priority_queue<ss>qq,_0_;
int Fa[maxn];
int dijstra(int st,int en){
	for(int i=0;i<maxn;i++) d[i]=INF;
	qq=_0_;
	qq.push(ss(0,st,0));
	while(!qq.empty()){
		ss th=qq.top();
		qq.pop();
//		printf("[%d %d %d]\n",th.from,th.to,th.len);
		if(d[th.to]!=INF) continue;
		d[th.to]=th.len;
		Fa[th.to]=th.from;
		if(th.to==en){
			return d[en];
		}
		for(vector<int>::iterator i=M[th.to].begin();i!=M[th.to].end();i++){
			if(d[*i]!=INF) continue;
			ss ne=ss(th.to,*i,d[th.to]+L[th.to][*i]);
//			printf("\t(%d %d %d)\n",ne.from,ne.to,ne.len);
			qq.push(ne);
		}
	}
	return INF;
}
void print(int x){
	if(x!=1) print(Fa[x]);
	printf("%d ",x);
}
int FF[maxn];
int main(){
	freopen("roadblock.in","r",stdin);
	freopen("roadblock.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		M[a].push_back(b);
		M[b].push_back(a);
		L[a][b]=L[b][a]=c;
	}
	int fir=dijstra(1,n);
//	for(int i=1;i<=n;i++) printf("[%d %d] ",d[i],Fa[i]);
//	print(n);
	int ans=fir;
	memcpy(FF,Fa,sizeof(Fa));
	for(int i=n;i!=1;i=FF[i]){
		int e=L[i][FF[i]];
		L[i][FF[i]]=L[FF[i]][i]=L[i][FF[i]]*2;
		ans=max(ans,dijstra(1,n));
		L[i][FF[i]]=L[FF[i]][i]=e;
	}
	printf("%d\n",ans-fir);
}
/*
5 7
2 1 5
1 3 1
3 2 8
3 5 7
3 4 3
2 4 7
4 5 2
*/
