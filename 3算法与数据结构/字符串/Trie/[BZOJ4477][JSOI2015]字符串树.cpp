#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000 
#define maxlogn 20
#define maxl 10
#define maxs 26
using namespace std;
int n,m;
char str[maxn+5][maxl+5];
char tmp[maxl+5];
struct persist_trie{
    int root[maxn+5];
    int sz[maxn*maxs+5];
    int ch[maxn*maxs+5][maxs];
    int ptr;
    inline int get_id(char c){
        return c-'a';
    }
    void insert(int pos,int pre,char* s){
        int now=root[pos]=++ptr,last=root[pre];
        int len=strlen(s+1);
        for(int i=1;i<=len;i++){
            for(int j=0;j<maxs;j++) ch[now][j]=ch[last][j];
            int c=get_id(s[i]);
            ch[now][c]=++ptr;
            now=ch[now][c];
            last=ch[last][c];
            sz[now]=sz[last]+1;//sz[p]p子树内字符串结尾的个数
            //显然s结尾往上的所有Trie节点的sz都要比原来+1
        }
    }
    int query(int pos,char *s){
        int now=root[pos];
        int len=strlen(s+1);
        for(int i=1;i<=len;i++){
            int c=get_id(s[i]);
            now=ch[now][c];
        }
        return sz[now];
    }
}T;

struct edge{
    int from;
    int to;
    int next;
}E[maxn*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v){
    sz++;
    E[sz].from=u;
    E[sz].to=v;
    E[sz].next=head[u];
    head[u]=sz;
}
int deep[maxn+5],anc[maxn+5][maxlogn+5];
void dfs(int x,int fa){
    T.insert(x,fa,str[x]);
    anc[x][0]=fa;
    for(int i=1;i<=maxlogn;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
    deep[x]=deep[fa]+1;
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(y!=fa){
            dfs(y,x);
        }
    }
}
int lca(int x,int y){
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=maxlogn;i>=0;i--){
        if(deep[anc[x][i]]>=deep[y]){
            x=anc[x][i];
        }
    }
    if(x==y) return x;
    for(int i=maxlogn;i>=0;i--){
        if(anc[x][i]!=anc[y][i]){
            x=anc[x][i];
            y=anc[y][i];
        }
    }
    return anc[x][0];
}




int main(){
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        if(u>v) swap(u,v);
        add_edge(u,v);
        scanf("%s",str[v]+1);
    }
    dfs(1,0);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %s",&u,&v,tmp+1);
        int lc=lca(u,v);
        int ans=T.query(u,tmp)+T.query(v,tmp)-2*T.query(lc,tmp);
        printf("%d\n",ans);
    }
} 
