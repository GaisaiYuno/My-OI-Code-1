#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define siz 10010
#define minn(a,b) (a<b?a:b)
using namespace std;
//ǿ��ͨ�������� 
int n,m,s,t,pos,top,cnt,corcnt;
int first[siz],dfn[siz],low[siz],cor[siz],corsiz[siz],st[siz];
bool in[siz];
vector <int> node[siz*10];
void tajan(int p,int form) {
    dfn[p]=low[p]=++cnt;
    st[++top]=p,in[p]=1;
    for(int i=0;i<node[p].size();++i)
     if(node[p][i]!=form) {
         if(!dfn[node[p][i]]){
            tajan(node[p][i],p);
            low[p]=minn(low[node[p][i]],low[p]);
         } else if(in[node[p][i]]) low[p]=minn(low[p],dfn[node[p][i]]);
     }
    int j;
    if(low[p]==dfn[p]) {
        corcnt++;
        do {
            j=st[top--],in[j]=0; 
            cor[j]=corcnt,corsiz[corcnt]++;
        }while(j!=p);
    }
}

//�ؽ�ͼ 
int rfirst[siz];
vector <int> rnode[siz*10];
void rebuild() {
    pos=0;
    for(int i=1;i<=n;++i)
     for(int j=0;j<node[i].size();++j)
       if(cor[i]!=cor[node[i][j]]) rnode[cor[i]].push_back(cor[node[i][j]]);
}

//LCA����
int q;
int u,v,dep[siz],T[siz][21];
void dfs(int p,int fa,int depth){
    dep[p]=depth,T[p][0]=fa;
    for(int i=0;i<rnode[p].size();++i)
     if(rnode[p][i]!=fa) dfs(rnode[p][i],p,depth+1);
}
int LCA(int u,int v) {
    if(dep[u]<dep[v]) swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=20;i>=0;--i)
      if(d&(1<<i)) u=T[u][i];
    if(u==v) return u;
    for(int i=20;i>=0;--i)
      if(T[u][i]!=T[v][i]) u=T[u][i],v=T[v][i];
    return T[u][0];
}

//�������
int tmp[64];
void print(int res) {
    if(res==0) { puts("0"); return ;}
    if(res<0) { putchar('-');res=0-res; }
    while(res) tmp[++tmp[0]]=res&1,res>>=1;
    while(*tmp) putchar(tmp[(*tmp)--]+'0');
    putchar('\n');
} 
int main(){

//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
    scanf("%d%d",&n,&m);
    while(m--) {
        scanf("%d%d",&s,&t);
        node[s].push_back(t);
        node[t].push_back(s);
    }
    for(int i=1;i<=n;++i)
     if(!dfn[i]) tajan(i,0);
    rebuild();
    dfs(1,0,0);
    for(int j=1;j<=20;++j)
     for(int i=1;i<=corcnt;++i)
      T[i][j]=T[T[i][j-1]][j-1];
    scanf("%d",&q);
    for(int i=1;i<=q;++i) {
        scanf("%d%d",&u,&v);
        int lca=LCA(cor[u],cor[v]);
        print(dep[cor[u]]+dep[cor[v]]-(dep[lca]<<1)+1);
    }
    return 0;
}
