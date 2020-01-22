#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 1000010
struct edge{ int v,nxt,id; }G[maxn<<1];
struct Edge{ int u,v; bool frog; }e[maxn];
int head[maxn],tot,cnt,used;
void add(int u,int v,int id){
    G[++tot].v=v; G[tot].id=id; G[tot].nxt=head[u]; head[u]=tot;
    G[++tot].v=u; G[tot].id=id; G[tot].nxt=head[v]; head[v]=tot;
}
int n,m,fa[maxn],f[maxn][21],dep[maxn],bel[maxn],s[maxn],ans[maxn];
bool vis[maxn];
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void dfs(int u){
    vis[u]=1;
    for(int v,i=head[u];i;i=G[i].nxt)
        if(f[u][0]!=(v=G[i].v)){
            f[v][0]=u;
            dep[v]=dep[u]+1; bel[v]=i;
            for(int j=1;(1<<j)<=dep[v];++j)
                f[v][j]=f[f[v][j-1]][j-1];
            dfs(v);
        }
}
inline int lca(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    for(int i=20;i>=0;--i)
        if(dep[u]<=dep[v]-(1<<i)) v=f[v][i];
    if(u==v) return u;
    for(int i=20;i>=0;--i)
        if(f[u][i]!=f[v][i]){ u=f[u][i]; v=f[v][i]; }
    return f[u][0];
}
void dfs2(int u){
    vis[u]=1;
    for(int i=head[u];i;i=G[i].nxt)
        if(f[u][0]!=G[i].v){ dfs2(G[i].v); s[u]+=s[G[i].v]; }
    //��������㲻�����ǣ���ô�������߾Ϳ��Ա�ɾ��
    if(s[u]==cnt) ans[++ans[0]]=G[bel[u]].id;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=m;++i){
        scanf("%d %d",&e[i].u,&e[i].v);
        int fu=find(e[i].u),fv=find(e[i].v);
        if(fu==fv) e[i].frog=1;
        else{ fa[fu]=fv; add(e[i].u,e[i].v,i); }
    }
    for(int i=1;i<=n;++i) if(!vis[i]) dfs(i);
    for(int i=1;i<=m;++i)
        if(e[i].frog){
            //���в�֣�ż�����滷��ͬռ�õı߲��ܱ�ɾ��
            int tmp=lca(e[i].u,e[i].v),tp=-1;
            printf("%d ",tmp);
            if(!((dep[e[i].u]-dep[e[i].v])&1)){ tp=1; ++cnt; used=i; }
            printf("%d %d %d\n",e[i].u,e[i].v,tp);
            s[e[i].u]+=tp; s[e[i].v]+=tp;
            s[tmp]-=2*tp;
        }
    //���û�л������б߶����Ա�ɾ��
    if(!cnt){
        printf("%d\n",m);
        for(int i=1;i<m;++i) printf("%d ",i); if(m) printf("%d",m);
        printf(" ");
        return 0;
    }
    memset(vis,0,sizeof(vis));
    //ֻ��һ���滷���滷�ϱ߶�����ɾ
    if(cnt==1) ans[++ans[0]]=used;
    for(int i=1;i<=n;++i) if(!vis[i]) dfs2(i);
    sort(ans+1,ans+1+ans[0]);
    printf("%d\n",ans[0]);
    for(int i=1;i<ans[0];++i) printf("%d ",ans[i]); if(ans[0]) printf("%d",ans[ans[0]]);
    printf(" ");
    return 0;
}
