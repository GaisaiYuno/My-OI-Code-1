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
    inline int query(int p,int q,int l,int r,int k){//[l,r]�б�ŵ�k�����,(�Ѿ�;����Ҫ)��ɢ��
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
    inline void ADD(int u,int v){Add_edge(u,v);Add_edge(v,u);}//����д��С����
    inline void dfs1(int u,int pre){
        L[u]=++dft,rev[dft]=u,fa[u][0]=pre,dep[u]=dep[pre]+1;
        for(int i=1;fa[u][i-1];i++) fa[u][i]=fa[fa[u][i-1]][i-1];
        Go(u) if(v^pre) dfs1(v,u);
        R[u]=dft;//�������dfn��
    }
#undef Go
    inline void init(){
        for(int i=1;i<n;i++) ADD(read(),read());
        dfs1(1,0);
        CMT.build(CMT.rt[0],1,n);
        for(int i=1;i<=n;i++) CMT.insert(CMT.rt[i-1],CMT.rt[i],1,n,rev[i]);//dfn��Ϊi�ĵ����ԭ�����(���)rev[i]��
        for(int i=2;i<=n;i++) log2[i]=log2[i>>1]+1;
    }
    inline int getdis(int u,int v){//ģ�����Ͼ���,LCA
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
    //�ؼ�
    inline int getrev(LL u){//ĳһ���������С���ĸ��ڵ���ģ�����еı��
        int rt=getrt(u);//rev[rt]Ϊ���ڵ���ģ�����е�λ��,���������ҳ���ŵ�u-L[rt]+1���,����rt��ģ�����¶�Ӧ��u
        return CMT.query(CMT.rt[TT::L[rev[rt]]-1],CMT.rt[TT::R[rev[rt]]],1,TT::n,u-L[rt]+1);
    }
    inline void build(){
        n=1,dep[1]=1,rev[1]=1,L[1]=1,R[1]=TT::n,Pcnt=TT::n;
        for(int i=1;i<=m;i++){
            int u=read();LL v=read();int rt=getrt(v);
            n++;
            dep[n]=dep[rt]+1,rev[n]=u,link[n]=v;//rev[]Ϊ������ڵ��Ӧ��ģ�����е�λ��
            L[n]=Pcnt+1,R[n]=Pcnt+TT::R[u]-TT::L[u]+1;
            Pcnt=R[n];
            fa[n][0]=rt,dis[n][0]=TT::dep[getrev(v)]-TT::dep[rev[rt]]+1;//�����ϵľ��붨��Ϊ��֮��ľ���
            for(int j=1;fa[n][j-1];j++) fa[n][j]=fa[fa[n][j-1]][j-1],dis[n][j]=dis[n][j-1]+dis[fa[n][j-1]][j-1];
        }
    }
    //��������:���кͷ����
    inline LL solve(LL u,LL v){
        int rtu=getrt(u),rtv=getrt(v);LL res=0;
        if(rtu==rtv) return TT::getdis(getrev(u),getrev(v));//ͬһ��С��
        if(dep[rtu]<dep[rtv]){swap(u,v);swap(rtu,rtv);}
        res+=TT::dep[getrev(u)]-TT::dep[rev[rtu]]; u=rtu;
        for(int i=TT::log2[dep[u]];~i;i--) if(dep[fa[u][i]]>dep[rtv]) res+=dis[u][i],u=fa[u][i];//�Ȳ�Ҫ����ͬһ���
        if(getrt(link[u])==rtv) return res+1+TT::getdis(getrev(link[u]),getrev(v));//�ڴ����Ͽ�����ͬһ������,Ҫ����
        res+=TT::dep[getrev(v)]-TT::dep[rev[rtv]]; v=rtv;
        if(dep[u]>dep[v]) res+=dis[u][0],u=fa[u][0];//Ȼ����ǳ������,Ҫ����ͬһ���
        for(int i=TT::log2[dep[u]];~i;i--) if(fa[u][i]!=fa[v][i]) res+=dis[u][i]+dis[v][i],u=fa[u][i],v=fa[v][i];//LCA����
        u=link[u],v=link[v],res+=2;
        return res+TT::getdis(getrev(u),getrev(v));//���һ��
    }
}

int main(){
    TT::n=read(),BT::m=read();int Q=read();
    TT::init();
    BT::build();
    while(Q--) printf("%lld\n",BT::solve(read(),read()));
}
