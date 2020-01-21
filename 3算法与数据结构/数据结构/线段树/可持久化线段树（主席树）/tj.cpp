#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug(x) cout<<#x<<"="<<x<<endl
using namespace std;
typedef long long LL;
const int INF=1e9+7;
inline LL read(){
    register LL x=0,f=1;register char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>=48&&c<=57)x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f*x;
}

const int N=1e5+5;
const int M=2e5+5;
const int logN=20;

struct Chairman_Tree{
    struct SGT{
        int lc,rc,sum;
    }t[N*logN];
    int rt[N],Pcnt;
#define ls (t[rt].lc)
#define rs (t[rt].rc)
    inline void build(int &rt,int l,int r){
        rt=++Pcnt;
        if(l==r) return;
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
    }
    inline void insert(int pre,int &rt,int l,int r,int pos){
        t[++Pcnt]=t[pre];
        t[rt=Pcnt].sum++;
        if(l==r) return;
        int mid=(l+r)>>1;
        if(pos<=mid) insert(t[pre].lc,ls,l,mid,pos);
        else insert(t[pre].rc,rs,mid+1,r,pos);
    }
    inline int query(int p,int q,int l,int r,int k){//[l,r]中编号第k大的数,(已经;不需要)离散化
        if(l==r) return l;// id[l]==l
        int mid=(l+r)>>1;
        int lcnt=t[t[q].lc].sum-t[t[p].lc].sum;
        if(k<=lcnt) return query(t[p].lc,t[q].lc,l,mid,k);
        else return query(t[p].rc,t[q].rc,mid+1,r,k-lcnt);
    }
#undef ls
#undef rs
}CMT;

namespace TT{ // Template_Tree
    struct Edge{int v,nxt;}e[M]; int first[N],Ecnt;
#define Go(u) for(register int i=first[u],v=e[i].v;i;v=e[i=e[i].nxt].v)
    int fa[N][logN+1],dep[N],L[N],R[N],rev[N],log2[N];
    int n,dft;
    inline void Add_edge(int u,int v){e[++Ecnt]=(Edge){v,first[u]};first[u]=Ecnt;}
    inline void ADD(int u,int v){Add_edge(u,v);Add_edge(v,u);}//这样写减小码量
    inline void dfs1(int u,int pre){
        L[u]=++dft,rev[dft]=u,fa[u][0]=pre,dep[u]=dep[pre]+1;
        for(int i=1;fa[u][i-1];i++) fa[u][i]=fa[fa[u][i-1]][i-1];
        Go(u) if(v^pre) dfs1(v,u);
        R[u]=dft;//利用这个dfn序
    }
#undef Go
    inline void init(){
        for(int i=1;i<n;i++) ADD(read(),read());
        dfs1(1,0);
        CMT.build(CMT.rt[0],1,n);
        for(int i=1;i<=n;i++) CMT.insert(CMT.rt[i-1],CMT.rt[i],1,n,rev[i]);//dfn序为i的点插入原来这个(编号)rev[i]点
        for(int i=2;i<=n;i++) log2[i]=log2[i>>1]+1;
    }
    inline int getdis(int u,int v){//模板树上距离,LCA
        int res=0;
        if(dep[u]<dep[v]) swap(u,v);
        for(int i=log2[dep[u]];~i;i--) if(dep[fa[u][i]]>=dep[v]) res+=(1<<i),u=fa[u][i];
        if(u==v) return res;
        for(int i=log2[dep[u]];~i;i--) if(fa[u][i]!=fa[v][i]) res+=(1<<(i+1)),u=fa[u][i],v=fa[v][i];
        return res+2;
    }
}

namespace BT{ // Big_Tree
    int fa[N][logN+1],dep[N],rev[N];LL dis[N][logN+1],L[N],R[N],link[N];
    int n,m;LL Pcnt;
    inline int getrt(LL u){
        int l=1,r=n,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(L[mid]<=u) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
    //关键
    inline int getrev(LL u){//某一个点相对于小树的根节点在模板树中的编号
        int rt=getrt(u);//rev[rt]为根节点在模板树中的位置,在这里面找出编号第u-L[rt]+1大的,就是rt在模板树下对应的u
        return CMT.query(CMT.rt[TT::L[rev[rt]]-1],CMT.rt[TT::R[rev[rt]]],1,TT::n,u-L[rt]+1);
    }
    inline void build(){
        n=1,dep[1]=1,rev[1]=1,L[1]=1,R[1]=TT::n,Pcnt=TT::n;
        for(int i=1;i<=m;i++){
            int u=read();LL v=read();int rt=getrt(v);
            n++;
            dep[n]=dep[rt]+1,rev[n]=u,link[n]=v;//rev[]为这个根节点对应的模板数中的位置
            L[n]=Pcnt+1,R[n]=Pcnt+TT::R[u]-TT::L[u]+1;
            Pcnt=R[n];
            fa[n][0]=rt,dis[n][0]=TT::dep[getrev(v)]-TT::dep[rev[rt]]+1;//大树上的距离定义为根之间的距离
            for(int j=1;fa[n][j-1];j++) fa[n][j]=fa[fa[n][j-1]][j-1],dis[n][j]=dis[n][j-1]+dis[fa[n][j-1]][j-1];
        }
    }
    //分类讨论:特判和分情况
    inline LL solve(LL u,LL v){
        int rtu=getrt(u),rtv=getrt(v);LL res=0;
        if(rtu==rtv) return TT::getdis(getrev(u),getrev(v));//同一棵小树
        if(dep[rtu]<dep[rtv]){swap(u,v);swap(rtu,rtv);}
        res+=TT::dep[getrev(u)]-TT::dep[rev[rtu]]; u=rtu;
        for(int i=TT::log2[dep[u]];~i;i--) if(dep[fa[u][i]]>dep[rtv]) res+=dis[u][i],u=fa[u][i];//先不要跳到同一深度
        if(getrt(link[u])==rtv) return res+1+TT::getdis(getrev(link[u]),getrev(v));//在大树上可能在同一条链上,要特判
        res+=TT::dep[getrev(v)]-TT::dep[rev[rtv]]; v=rtv;
        if(dep[u]>dep[v]) res+=dis[u][0],u=fa[u][0];//然后才是常规情况,要跳到同一深度
        for(int i=TT::log2[dep[u]];~i;i--) if(fa[u][i]!=fa[v][i]) res+=dis[u][i]+dis[v][i],u=fa[u][i],v=fa[v][i];//LCA求法了
        u=link[u],v=link[v],res+=2;
        return res+TT::getdis(getrev(u),getrev(v));//最后一步
    }
}

int main(){
    TT::n=read(),BT::m=read();int Q=read();
    TT::init();
    BT::build();
    while(Q--) printf("%lld\n",BT::solve(read(),read()));
}
