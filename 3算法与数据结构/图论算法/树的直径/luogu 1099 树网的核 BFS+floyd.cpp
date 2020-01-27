#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 305
#define maxm 40005
#define INF 1061109567
using namespace std;
int used[maxn];
int dis[maxn][maxn];
int n,m;
struct node{
    int x;
    int t;
    node(){} 
    node(int xx,int tim){
        x=xx;
        t=tim;
    }
};
node bfs(int s){
    memset(used,0,sizeof(used));
    queue<node>q;
    q.push(node(s,0));
    node now,nex;
    int tx,ty;
    int maxt=0,maxx=s;
    used[s]=1;
    while(!q.empty()){
        now=q.front();
        q.pop();
        int u=now.x;
        if(now.t>maxt){
        	maxx=now.x;
        	maxt=now.t;
        } 
        used[u]=1;
        for(int i=1;i<=n;i++){
            if(!used[i]&&dis[u][i]!=INF){
                used[i]=1;
                q.push(node(i,now.t+dis[u][i]));
            }
        } 
    }
    return node(maxx,maxt);
}
void floyd(){
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
}
int main(){
    int u,v,w;
    int s;
    scanf("%d %d",&n,&s);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=INF;
        }
    }
    for(int i=1;i<=n-1;i++){
        scanf("%d %d %d",&u,&v,&w);
        dis[u][v]=dis[v][u]=w;
    } 
    node tmp1=bfs(1);
    node tmp2=bfs(tmp1.x);
    int left=tmp1.x;
    int right=tmp2.x;
    int len=tmp2.t;
    floyd(); 
    int ans=INF,ecc=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[left][i]+dis[i][j]+dis[j][right]==len&&dis[i][j]<=s){
                ecc=0;
                for(int k=1;k<=n;k++){
                    if(k!=i&&k!=j) ecc=max(ecc,(dis[k][i]+dis[k][j]-dis[i][j])/2);
                }
                ans=min(ans,ecc);
            }
        }
    }
    printf("%d\n",ans);
//	printf("%d\n",tmp2.t);

} 
