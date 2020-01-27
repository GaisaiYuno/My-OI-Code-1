#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1e9
#define tot (n*m*3)
#define left(i,j) ((i-1)*m+j)
#define now(i,j) (((i-1)*m+j)+n*m)
#define right(i,j) (((i-1)*m+j)+(n*m<<1))
using namespace std;
inline int read(){
    int re=0,flag=1;char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') flag=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
    return re*flag;
}
const int dx[9]={0,-1,-1,-1,0,0,1,1,1},dy[9]={0,-1,0,1,-1,1,-1,0,1};
int n,cnt=-1,m,first[2010],dis[2010],vis[2010],ans=0;
struct edge{
    int to,next,w,cap;
}a[50010];
inline void add(int u,int v,int w,int cap){
	printf("%d->%d flow=%d cost=%d\n",u,v,cap,w);
    a[++cnt]=(edge){v,first[u],w,cap};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],-w,0};first[v]=cnt;
}
int q[10010];
bool spfa(int s,int t){
    int head=0,tail=1,i,v,u,w;
    memset(dis,-1,sizeof(dis));memset(vis,0,sizeof(vis));
    q[0]=t;vis[t]=1;dis[t]=0;
    while(head<tail){
        u=q[head++];vis[u]=0;
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;w=a[i].w;
            if(a[i^1].cap&&((dis[v]==-1)||(dis[v]>dis[u]-w))){
                dis[v]=dis[u]-w;
                if(!vis[v]) q[tail++]=v,vis[v]=1;
            }
        }
    }
    return ~dis[s];
}
int dfs(int u,int t,int limit){
    if(u==t||!limit){vis[u]=1;return limit;}
    int i,v,f,flow=0,w;vis[u]=1;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;w=a[i].w;
        if(!vis[v]&&a[i].cap&&dis[v]==dis[u]-w){
            if(!(f=dfs(v,t,min(limit,a[i].cap)))) continue;
            a[i].cap-=f;a[i^1].cap+=f;
            flow+=f;limit-=f;ans+=w*f;
            if(!limit) return flow;
        }
    }
    return flow;
}
int zkw(int s,int t){
    int re=0;
    while(spfa(s,t)){
        vis[t]=1;
        while(vis[t]){
            memset(vis,0,sizeof(vis));
            re+=dfs(s,t,inf);
        }
    }
    return re;
}
int x1[30][30],x2[30][30];
int main(){
    memset(first,-1,sizeof(first));
    int i,j,t1=0,t2=0,ti,tj,k;char s[30];
    n=read();m=read();
    for(i=1;i<=n;i++){
        scanf("%s",s);
        for(j=1;j<=m;j++){
            if(s[j-1]=='1'){
                t1++;add(0,now(i,j),0,1);
                x1[i][j]=1;
            }
        }
    }
    for(i=1;i<=n;i++){
        scanf("%s",s);
        for(j=1;j<=m;j++){
            if(s[j-1]=='1'){
                t2++;add(now(i,j),tot+1,0,1);
                x2[i][j]=1;
            }
        }
    }
    if(t1!=t2){
        puts("-1");return 0;
    }
    for(i=1;i<=n;i++){
        scanf("%s",s);
        for(j=1;j<=m;j++){
            t2=s[j-1]-'0';
            if(x1[i][j]==x2[i][j]) 
                add(left(i,j),now(i,j),0,t2/2),add(now(i,j),right(i,j),0,t2/2);
            if(x1[i][j]&&!x2[i][j])
                add(left(i,j),now(i,j),0,t2/2),add(now(i,j),right(i,j),0,(t2+1)/2);
            if(!x1[i][j]&&x2[i][j])
                add(left(i,j),now(i,j),0,(t2+1)/2),add(now(i,j),right(i,j),0,t2/2);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            for(k=1;k<=8;k++){
                ti=i+dx[k];tj=j+dy[k];
                if(ti<1||ti>n||tj<1||tj>m) continue;
                add(right(i,j),left(ti,tj),1,inf);
            }
        }
    }
    if(zkw(0,tot+1)!=t1){
        puts("-1");return 0;
    }
    cout<<ans<<endl;
}
