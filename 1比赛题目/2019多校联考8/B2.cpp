#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
#define maxn 100000
#define maxc 10
using namespace std;
typedef long long ll;
int n;
char s[maxn+5];

vector<int>E[maxc+5];
void add_edge(int u,int v){
	E[u].push_back(v);
	E[v].push_back(u);
//	printf("(%d,%d)\n",u,v);
}

int cnts[maxc+5];
int cnte[maxc+5][maxc+5];
int seg[maxc+5];
int sum[maxc+5];
int val[maxc+5];
struct node{
	int id;
	int dis;
	node(){
		
	}
	node(int _id,int _dis){
		id=_id;
		dis=_dis;
	}
	friend bool operator < (node p,node q){
		return p.dis>q.dis;
	}
};
int len[maxc+5][maxc+5];
int dist[maxc+5][maxc+5];
bool vis[maxc+5];
void dijkstra(int s,int *dist){
	priority_queue<node>q;
	for(int i=1;i<=8;i++){
		dist[i]=INF;
		vis[i]=0;
	}
	dist[s]=val[s];
	q.push(node(s,val[s]));
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int y=1;y<=8;y++){
			if(len[x][y]==INF||cnts[y]==0) continue;
			if(dist[y]>dist[x]+len[x][y]+val[y]){
				dist[y]=dist[x]+len[x][y]+val[y];
				q.push(node(y,dist[y]));
			}
		}
	}
}



int main(){
//	freopen("10.in","r",stdin);
	scanf("%d",&n);
	scanf("%s",s+1);
	memset(len,0x3f,sizeof(len));
	for(int i=1;i<=n;i++){
		cnts[s[i]-'a'+1]++;
	}
	int xx=0;
	for(int i=1;i<=n;i++){
		if(s[i]!=s[i-1]){
			seg[s[i]-'a'+1]++;
			len[s[i]-'a'+1][s[i-1]-'a'+1]=len[s[i-1]-'a'+1][s[i]-'a'+1]=1;
			cnte[s[i]-'a'+1][s[i-1]-'a'+1]=cnte[s[i-1]-'a'+1][s[i]-'a'+1]+=1;
		}
	}
	for(int i=1;i<=8;i++){
//		if(cnts[i]==0) continue;
		val[i]=(cnts[i]>1)?1:0;
	}
	for(int i=1;i<=8;i++){
		if(cnts[i]>0) dijkstra(i,dist[i]);
	}
	int maxd=0;
	for(int i=1;i<=8;i++){
		for(int j=i+1;j<=8;j++){
			if(cnts[i]==0||cnts[j]==0) continue;
			maxd=max(maxd,dist[i][j]);
		}
	}
	printf("%d ",maxd);
	ll cnt=0;
	for(int i=1;i<=8;i++){
		for(int j=i+1;j<=8;j++){
			if(cnts[i]==0||cnts[j]==0) continue;
			if(dist[i][j]==maxd){
				cnt+=(ll)(cnts[i]-seg[i])*(cnts[j]-seg[j]);
			}
		}
	}
	printf("%lld\n",cnt);
//	for(int i=1;i<=8;i++){
//		if(cnts[i]==0) continue;
//		val[i]=(cnts[i]>1)?1:0;
////		ff[i]=(cnts[i]>1)
//	}
//	int maxd=0;
//	for(int i=1;i<=8;i++){
//		if(cnts[i]>0) maxd++;
//		if(cnts[i]>1) maxd++;
//	}
//	maxd--;
//	printf("%d\n",maxd);
//	ll f1=seg[s[1]],f2=
}
