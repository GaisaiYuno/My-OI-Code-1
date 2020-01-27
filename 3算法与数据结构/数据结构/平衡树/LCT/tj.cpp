//Pastoral Oddities
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int,int> Ipair;
inline char gc()
{
    static char now[1<<16],*S,*T;
    if(S==T) {T=(S=now)+fread(now,1,1<<16,stdin); if(S==T) return EOF;}
    return *S++;
}
inline int read()
{
    int x=0; char ch=gc();
    while(ch<'0'||'9'<ch) ch=gc();
    while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=gc();
    return x;
}
int const N=4e5+10;
int const INF=0x3F3F3F3F;
int n,m;
struct edge{int u,v;} ed[N];
set<Ipair> st;
int fa[N],ch[N][2],siz[N],isiz[N];
int val[N],maxL[N]; bool rev[N];
int wh(int p) {return p==ch[fa[p]][1];}
int notRt(int p) {return p==ch[fa[p]][wh(p)];}
void update(int p)
{
    int ch0=ch[p][0],ch1=ch[p][1];
    siz[p]=siz[ch0]+1+siz[ch1]+isiz[p];
    int maxP=max(val[p],max(val[maxL[ch0]],val[maxL[ch1]]));
    if(val[p]==maxP) maxL[p]=p;
    else if(val[maxL[ch0]]==maxP) maxL[p]=maxL[ch0];
    else if(val[maxL[ch1]]==maxP) maxL[p]=maxL[ch1];
}
void pushdw(int p) {if(rev[p]) swap(ch[p][0],ch[p][1]),rev[ch[p][0]]^=1,rev[ch[p][1]]^=1,rev[p]=false;}
void rotate(int p)
{
    int q=fa[p],r=fa[q],w=wh(p);
    fa[p]=r; if(notRt(q)) ch[r][wh(q)]=p;
    fa[ch[q][w]=ch[p][w^1]]=q;
    fa[ch[p][w^1]=q]=p;
    update(q),update(p);
}
void pushRt(int p) {if(notRt(p)) pushRt(fa[p]); pushdw(p);}
void splay(int p)
{
    pushRt(p);
    for(int q=fa[p];notRt(p);rotate(p),q=fa[p]) if(notRt(q)) rotate(wh(p)^wh(q)?p:q);
}
void access(int p) {for(int q=0;p;q=p,p=fa[p]) splay(p),isiz[p]+=siz[ch[p][1]]-siz[q],ch[p][1]=q,update(p);}
void makeRt(int p) {access(p),splay(p),rev[p]^=1;}
void path(int p,int q) {makeRt(p),access(q),splay(q);}
void link(int i)
{
    int p=ed[i].u,q=ed[i].v; makeRt(p),makeRt(q);
    fa[p]=n+i,isiz[n+i]+=siz[p]; update(n+i);
    fa[n+i]=q,isiz[q]+=siz[n+i]; update(q);
}
void clear(int p) {fa[p]=ch[p][0]=ch[p][1]=0,isiz[p]=0; update(p);}
void cut(int i)
{
    int p=ed[i].u,q=ed[i].v; path(p,q);
    fa[p]=ch[p][1]=0; ch[q][0]=0;
    clear(n+i); update(p),update(q);
}
int find(int p) {access(p),splay(p); while(ch[p][0]) p=ch[p][0]; return p;}
int odd(int p) {return siz[p]+1>>1&1;}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++) val[i]=-INF,update(i);
    for(int i=1,cnt=n;i<=m;i++)
    {
        int u=read(),v=read(),w=read();
        ed[i].u=u,ed[i].v=v; val[n+i]=w,maxL[n+i]=n+i;
        if(find(u)==find(v))
        {
            path(u,v); int id=maxL[v]-n,w0=val[id+n];
            if(w<w0) cut(id),link(i),st.erase(make_pair(w0,id));
            else {printf("%d\n",cnt?-1:st.rbegin()->first); continue;}
        }
        else
        {
            makeRt(u),cnt-=odd(u); makeRt(v),cnt-=odd(v);
            link(i),cnt+=odd(v);
        }
        st.insert(make_pair(val[i+n],i));
        if(cnt) {puts("-1"); continue;}
        while(true)
        {
            int id=st.rbegin()->second; u=ed[id].u,v=ed[id].v;
            path(u,v); if(odd(u)) break;
            cut(id); st.erase(*st.rbegin());
        }
        printf("%d\n",st.rbegin()->first);
    }
    return 0;
}
