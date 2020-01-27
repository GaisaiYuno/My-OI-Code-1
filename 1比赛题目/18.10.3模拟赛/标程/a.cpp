#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010
#define ll long long
#define inf 0x3f3f3f3f
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,m,fa[N],ans[N],sz[N];
struct Edge{
    int x,y,val;
}e[N];
struct qu{
    int x,val,id;
}q[N];
inline bool cmp(Edge a,Edge b){return a.val>b.val;}
inline bool cmp1(qu a,qu b){return a.val>b.val;}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){
    int xx=find(x),yy=find(y);
    fa[xx]=yy;sz[yy]+=sz[xx];
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<n;++i) e[i].x=read(),e[i].y=read(),e[i].val=read();
    sort(e+1,e+n,cmp);
    for(int i=1;i<=n;++i) fa[i]=i,sz[i]=1;
    for(int i=1;i<=m;++i) q[i].val=read(),q[i].x=read(),q[i].id=i;
    sort(q+1,q+m+1,cmp1);int num=1;
    for(int i=1;i<=m;++i){
        while(num<n&&e[num].val>=q[i].val) merge(e[num].x,e[num].y),++num;
        ans[q[i].id]=sz[find(q[i].x)]-1;
    }for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
    return 0;
}
