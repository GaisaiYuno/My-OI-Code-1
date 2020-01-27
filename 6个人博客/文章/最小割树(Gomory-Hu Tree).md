## 最小割树(Gomory-Hu Tree)

### 前置知识

Gomory-Hu Tree是用来解决无向图最小割的问题的，所以我们需要了解无向图最小割的定义

和有向图类似，无向图上两点(x,y)的割定义为一个边集E，满足去掉该边集后x,y不联通。最小割即为所有的割中权值之和最小的割

通过这条割我们把点集划为两个部分，x所在的一个记为$V_x$,y所在的一个记为$V_y$

### 定义

首先我们知道，一个n个点的无向图上，两点之间的最小割只有n-1中，因此一定存在一棵树，满足树上两点的最小割等于原图上两点的最小割。

最小割树的定义如下：

> 定义一棵树T为最小割树，如果对于树上的所有边(s,t)，树上去掉(s,t)后产生的两个集合恰好是原图上(s,t)的最小割把原图分成的两个集合，且边(u,v)的权值等于原图上(u,v)的最小割

很多博客里把Gomory-Hu树定义为树上边(u,v)的权值=图上(u,v)的最小割，而忽视了删掉边(u,v)后点集的关系，是错误的。那是等价流树(Equivalent Flow Tree)的定义。如果最小割树不是像上面一样定义的，那么下面的最小割树的性质定理就无法证明

> 原图上u,v两点最小割就是最小割树上u到v的路径上权值最小的边

### 最小割树的构造

根据定义：**树上去掉(s,t)后产生的两个集合恰好是原图上(s,t)的最小割把原图分成的两个集合**。
我们可以直接按定义构造最小割树

最小割树的构造是递归实现的。

在当前点集随意选取两个点u,v，在原图上跑出他们之间的最小割，然后就在树上连一条从u到v,权值为$\lambda(u,v)$的边。

然后找出u,v分属的两个点集，对这两个点集递归进行操作。当点集中的点只剩一个的时候停止递归

时间复杂度$O(n^3m)$，但很难卡满（实际上就是跑了n次dinic)

```cpp
int node[maxv];//node[i]里面存储点的编号
int tmp1[maxv],tmp2[maxv];
void build(int l,int r){
        if(l==r) return;
        int s=node[l],t=node[l+1];//任选两个点
        int cut=network_flow::dinic(s,t);
        add_edge(s,t,cut);
        int cnt1=0,cnt2=0;
        for(int i=l;i<=r;i++){
            if(network_flow::deep[node[i]]) tmp1[++cnt1]=node[i];
            else tmp2[++cnt2]=node[i];
            //考虑dinic算法中的最后一次bfs,因为现在残量网络上s到达不了t,所以bfs访问到的点就是s所在的点集，它们的deep不0
        }
        for(int i=l;i<=l+cnt1-1;i++) node[i]=tmp1[i-l+1];
        for(int i=l+cnt1;i<=r;i++) node[i]=tmp2[i-cnt1-l+1];
        build(l,l+cnt1-1);
        build(l+cnt1,r);
    }
```



### 最小割树的查询

最小割树满足一个重要的性质：

> 原图上u,v两点最小割就是最小割树上u到v的路径上权值最小的边

因此我们直接对建出的最小割树进行树上倍增即可

该性质的正确性证明见下方



### 正确性证明

为了下文描述方便，我们定义$\lambda (a,b)$表示a,b的最小割的权值

> **引理1** 对于任意$p \in V_x,q \in V_y​$，有$\lambda(x,y) \geq \lambda(p,q) ​$

证明：

​	假设$\lambda(x,y) < \lambda(p,q) $,那么用割断(x,y)的代价割不断(p,q),而p与x联通，p与y联通，那么(x,y)就割不断了，这与最小割的定义矛盾，因此引理成立。



> **定理1** :对于任意不同的三点$a,b,c​$,    $\lambda(a,b) \geq min(\lambda(a,c),\lambda(c,b))​$

证明：考虑$\lambda(a,b) \ , \lambda(a,c)\ ,\lambda(c,b)​$中最小的一对，不妨设为$\lambda(a,b)​$

![](https://i.loli.net/2019/04/24/5cbfd321327f7.png)

再讨论c在删掉(a,b)的割边之后与a联通还是与b联通，不妨设为与b，另一种同理。由引理1：$\lambda(a,c) \leq \lambda(a,b)​$

又因为我们之前假设过$\lambda(a,b)​$是最小的，因此$\lambda(a,c) \geq \lambda(a,b)​$,所以$\lambda(a,c)=\lambda(a,b)​$

因此$\lambda(a,b) \ , \lambda(a,c)\ ,\lambda(c,b)$中一定有两个较小值，一个较大值。

若$\lambda(a,b) $是小的，则$\lambda(a,c)\ ,\lambda(c,b)$中一个较大的,一个较小的，取min之后还是较小值，定理显然成立

若$\lambda(a,b) $是大的，则$\lambda(a,c)\ ,\lambda(c,b)$均是较小值，定理显然成立





> **定理1的推论**  对于任意不同的两点u,v, $\lambda(u,v) \geq min(\lambda(u,w_1),\lambda(w_1,w_2),\lambda(w_2,w_3) \dots , \lambda(w_k,v))$



> **定理2** 对于任意不同的两点x,y,令p,q为最小割树x到y路径上的两点，且$\lambda(p,q)​$最小，那么$\lambda(p,q)=\lambda(x,y)​$.也就是说，u,v两点最小割就是最小割树上u到v的路径上权值最小的边

由定理1的推论可知$\lambda(x,y) \geq \lambda(p,q)$

又根据最小割树的定义，x,y在p,q最小割的两侧，则$\lambda(p,q) \geq \lambda(x,y)​$

因此$\lambda(x,y)=\lambda(p,q)​$



### 题目

首先是模板

https://www.luogu.org/problemnew/show/P4897

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#define INF 0x3f3f3f3f
#define maxv 505
#define maxe 1505
#define maxlogv 10 
using namespace std;
int n,m,q;
namespace network_flow{ 
    struct edge{
        int from;
        int to;
        int next;
        int flow;
    }E[maxe<<2];
    int head[maxv];
    int deep[maxv];
    int sz=1;
    void add_edge(int u,int v,int w){
        sz++;
        E[sz].from=u;
        E[sz].to=v;
        E[sz].next=head[u];
        E[sz].flow=w;
        head[u]=sz;
        sz++;
        E[sz].from=v;
        E[sz].to=u;
        E[sz].next=head[v];
        E[sz].flow=0;
        head[v]=sz;
    }
    bool bfs(int s,int t){
        memset(deep,0,sizeof(deep));
        deep[s]=1;
        queue<int>q;
        q.push(s);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=head[x];i;i=E[i].next){
                int y=E[i].to;
                if(!deep[y]&&E[i].flow){
                    deep[y]=deep[x]+1;
                    q.push(y);
                }
            }
        }
        return deep[t]!=0;
    }
    int dfs(int x,int t,int minf){
        if(x==t) return minf;
        int k,rest=minf;
        for(int i=head[x];i;i=E[i].next){
            int y=E[i].to;
            if(deep[y]==deep[x]+1&&E[i].flow){
                k=dfs(y,t,min(rest,E[i].flow));
                rest-=k;
                E[i].flow-=k;
                E[i^1].flow+=k;
                if(k==0) deep[y]=0;
                if(rest==0) break;
            }
        } 
        return minf-rest;
    }
    void init(){
        for(int i=2;i<=sz;i+=2){
            E[i].flow=(E[i].flow+E[i^1].flow);
            E[i^1].flow=0;
        }
    }
    int dinic(int s,int t){
        init();
        int ans=0,now=0;
        while(bfs(s,t)){
            while(now=dfs(s,t,INF)) ans+=now;
        }
        return ans;
    }

} 

namespace mincut_tree{
    struct edge{
        int from;
        int to;
        int next;
        int len;
    }E[maxv<<1];
    int head[maxv];
    int sz=1;
    void add_edge(int u,int v,int w){
//		printf("tree: %d->%d len=%d\n",u,v,w);
        sz++;
        E[sz].from=u;
        E[sz].to=v;
        E[sz].next=head[u];
        E[sz].len=w;
        head[u]=sz;
        sz++;
        E[sz].from=v;
        E[sz].to=u;
        E[sz].next=head[v];
        E[sz].len=w;
        head[v]=sz;
    }
    
    int node[maxv];
    int tmp1[maxv],tmp2[maxv];
    void build(int l,int r){
        if(l==r) return;
        int s=node[l],t=node[l+1];
        int cut=network_flow::dinic(s,t);
        add_edge(s,t,cut);
        int cnt1=0,cnt2=0;
        for(int i=l;i<=r;i++){
            if(network_flow::deep[node[i]]) tmp1[++cnt1]=node[i];
            else tmp2[++cnt2]=node[i];
        }
        for(int i=l;i<=l+cnt1-1;i++) node[i]=tmp1[i-l+1];
        for(int i=l+cnt1;i<=r;i++) node[i]=tmp2[i-cnt1-l+1];
        build(l,l+cnt1-1);
        build(l+cnt1,r);
    }
    
    int log2n;
    int deep[maxv];
    int anc[maxv][maxlogv];
    int minl[maxv][maxlogv];
    void dfs(int x,int fa){
        deep[x]=deep[fa]+1;
        for(int i=1;i<=log2n;i++){
            anc[x][i]=anc[anc[x][i-1]][i-1];
            minl[x][i]=min(minl[x][i-1],minl[anc[x][i-1]][i-1]);
        }
        for(int i=head[x];i;i=E[i].next){
            int y=E[i].to;
            if(y!=fa){
                anc[y][0]=x;
                minl[y][0]=E[i].len;
                dfs(y,x);
            }
        }
    }
    
    void work(){
        log2n=log2(n)+1;
        for(int i=1;i<=n;i++) node[i]=i;
        build(1,n);
        dfs(1,0);
    }
    
    int query(int x,int y){
        int ans=INF;
        if(deep[x]<deep[y]) swap(x,y);
        for(int i=log2n;i>=0;i--){
            if(deep[anc[x][i]]>=deep[y]){
                ans=min(ans,minl[x][i]);
                x=anc[x][i];
            }
        }
        if(x==y) return ans;
        for(int i=log2n;i>=0;i--){
            if(anc[x][i]!=anc[y][i]){
                ans=min(ans,minl[x][i]);
                ans=min(ans,minl[y][i]);
                x=anc[x][i];
                y=anc[y][i];
            }
        }
        ans=min(ans,minl[x][0]);
        ans=min(ans,minl[y][0]);
        return ans;
    }
}

int main(){
    int u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        network_flow::add_edge(u,v,w); 
        network_flow::add_edge(v,u,w);
    }
    mincut_tree::work();
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&u,&v);
        int ans=mincut_tree::query(u,v);
        if(ans==INF) ans=-1;
        printf("%d\n",ans);
    }
}

```

以及两道例题

####  [CQOI2016]不同的最小割

https://www.luogu.org/problemnew/show/P4123

先建出最小割树，然后枚举所有点对，将求出的最小割值存入一个STL set

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<set>
#define INF 0x3f3f3f3f
#define maxv 855
#define maxe 8505
#define maxlogv 15
using namespace std;
int n,m,q;
namespace network_flow{ 
    struct edge{
        int from;
        int to;
        int next;
        int flow;
    }E[maxe<<2];
    int head[maxv];
    int deep[maxv];
    int sz=1;
    void add_edge(int u,int v,int w){
        sz++;
        E[sz].from=u;
        E[sz].to=v;
        E[sz].next=head[u];
        E[sz].flow=w;
        head[u]=sz;
        sz++;
        E[sz].from=v;
        E[sz].to=u;
        E[sz].next=head[v];
        E[sz].flow=0;
        head[v]=sz;
    }
    bool bfs(int s,int t){
        memset(deep,0,sizeof(deep));
        deep[s]=1;
        queue<int>q;
        q.push(s);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=head[x];i;i=E[i].next){
                int y=E[i].to;
                if(!deep[y]&&E[i].flow){
                    deep[y]=deep[x]+1;
                    q.push(y);
                }
            }
        }
        return deep[t]!=0;
    }
    int dfs(int x,int t,int minf){
        if(x==t) return minf;
        int k,rest=minf;
        for(int i=head[x];i;i=E[i].next){
            int y=E[i].to;
            if(deep[y]==deep[x]+1&&E[i].flow){
                k=dfs(y,t,min(rest,E[i].flow));
                rest-=k;
                E[i].flow-=k;
                E[i^1].flow+=k;
                if(k==0) deep[y]=0;
                if(rest==0) break;
            }
        } 
        return minf-rest;
    }
    void init(){
        for(int i=2;i<=sz;i+=2){
            E[i].flow=(E[i].flow+E[i^1].flow);
            E[i^1].flow=0;
        }
    }
    int dinic(int s,int t){
        init();
        int ans=0,now=0;
        while(bfs(s,t)){
            while(now=dfs(s,t,INF)) ans+=now;
        }
        return ans;
    }

} 

namespace mincut_tree{
    struct edge{
        int from;
        int to;
        int next;
        int len;
    }E[maxv<<1];
    int head[maxv];
    int sz=1;
    void add_edge(int u,int v,int w){
//		printf("tree: %d->%d len=%d\n",u,v,w);
        sz++;
        E[sz].from=u;
        E[sz].to=v;
        E[sz].next=head[u];
        E[sz].len=w;
        head[u]=sz;
        sz++;
        E[sz].from=v;
        E[sz].to=u;
        E[sz].next=head[v];
        E[sz].len=w;
        head[v]=sz;
    }
    
    int node[maxv];
    int tmp1[maxv],tmp2[maxv];
    void build(int l,int r){
        if(l==r) return;
        int s=node[l],t=node[l+1];
        int cut=network_flow::dinic(s,t);
        add_edge(s,t,cut);
        int cnt1=0,cnt2=0;
        for(int i=l;i<=r;i++){
            if(network_flow::deep[node[i]]) tmp1[++cnt1]=node[i];
            else tmp2[++cnt2]=node[i];
        }
        for(int i=l;i<=l+cnt1-1;i++) node[i]=tmp1[i-l+1];
        for(int i=l+cnt1;i<=r;i++) node[i]=tmp2[i-cnt1-l+1];
        build(l,l+cnt1-1);
        build(l+cnt1,r);
    }
    
    int log2n;
    int deep[maxv];
    int anc[maxv][maxlogv];
    int minl[maxv][maxlogv];
    void dfs(int x,int fa){
        deep[x]=deep[fa]+1;
        for(int i=1;i<=log2n;i++){
            anc[x][i]=anc[anc[x][i-1]][i-1];
            minl[x][i]=min(minl[x][i-1],minl[anc[x][i-1]][i-1]);
        }
        for(int i=head[x];i;i=E[i].next){
            int y=E[i].to;
            if(y!=fa){
                anc[y][0]=x;
                minl[y][0]=E[i].len;
                dfs(y,x);
            }
        }
    }
    
    void work(){
        log2n=log2(n)+1;
        for(int i=1;i<=n;i++) node[i]=i;
        build(1,n);
        dfs(1,0);
    }
    
    int query(int x,int y){
        int ans=INF;
        if(deep[x]<deep[y]) swap(x,y);
        for(int i=log2n;i>=0;i--){
            if(deep[anc[x][i]]>=deep[y]){
                ans=min(ans,minl[x][i]);
                x=anc[x][i];
            }
        }
        if(x==y) return ans;
        for(int i=log2n;i>=0;i--){
            if(anc[x][i]!=anc[y][i]){
                ans=min(ans,minl[x][i]);
                ans=min(ans,minl[y][i]);
                x=anc[x][i];
                y=anc[y][i];
            }
        }
        ans=min(ans,minl[x][0]);
        ans=min(ans,minl[y][0]);
        return ans;
    }
}

set<int>S;
int main(){
    int u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        network_flow::add_edge(u,v,w); 
        network_flow::add_edge(v,u,w);
    }
    mincut_tree::work();
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            S.insert(mincut_tree::query(i,j));
        }
    }
    printf("%d\n",S.size()); 
}


```



#### [ZJOI2011]最小割

https://www.luogu.org/problemnew/show/P4123

先建出最小割树，然后枚举所有点对，将求出的最小割值排序，然后二分查找就可以了

```cpp
//BZOJ 2229
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
#define maxv 155
#define maxe 3005
#define maxlogv 10
using namespace std;
int n,m,q;
namespace network_flow {
    struct edge {
        int from;
        int to;
        int next;
        int flow;
    } E[maxe<<2];
    int head[maxv];
    int deep[maxv];
    int sz=1;
    void add_edge(int u,int v,int w) {
        sz++;
        E[sz].from=u;
        E[sz].to=v;
        E[sz].next=head[u];
        E[sz].flow=w;
        head[u]=sz;
        sz++;
        E[sz].from=v;
        E[sz].to=u;
        E[sz].next=head[v];
        E[sz].flow=0;
        head[v]=sz;
    }
    bool bfs(int s,int t) {
        memset(deep,0,sizeof(deep));
        deep[s]=1;
        queue<int>q;
        q.push(s);
        while(!q.empty()) {
            int x=q.front();
            q.pop();
            for(int i=head[x]; i; i=E[i].next) {
                int y=E[i].to;
                if(!deep[y]&&E[i].flow) {
                    deep[y]=deep[x]+1;
                    q.push(y);
                }
            }
        }
        return deep[t]!=0;
    }
    int dfs(int x,int t,int minf) {
        if(x==t) return minf;
        int k,rest=minf;
        for(int i=head[x]; i; i=E[i].next) {
            int y=E[i].to;
            if(deep[y]==deep[x]+1&&E[i].flow) {
                k=dfs(y,t,min(rest,E[i].flow));
                rest-=k;
                E[i].flow-=k;
                E[i^1].flow+=k;
                if(k==0) deep[y]=0;
                if(rest==0) break;
            }
        }
        return minf-rest;
    }
    void init() {
        for(int i=2; i<=sz; i+=2) {
            E[i].flow=(E[i].flow+E[i^1].flow);
            E[i^1].flow=0;
        }
    }
    int dinic(int s,int t) {
        init();
        int ans=0,now=0;
        while(bfs(s,t)) {
            while(now=dfs(s,t,INF)) ans+=now;
        }
        return ans;
    }

}

namespace mincut_tree {
    struct edge {
        int from;
        int to;
        int next;
        int len;
    } E[maxv<<1];
    int head[maxv];
    int sz=1;
    void add_edge(int u,int v,int w) {
//		printf("tree: %d->%d len=%d\n",u,v,w);
        sz++;
        E[sz].from=u;
        E[sz].to=v;
        E[sz].next=head[u];
        E[sz].len=w;
        head[u]=sz;
        sz++;
        E[sz].from=v;
        E[sz].to=u;
        E[sz].next=head[v];
        E[sz].len=w;
        head[v]=sz;
    }

    int node[maxv];
    int tmp1[maxv],tmp2[maxv];
    void build(int l,int r) {
        if(l==r) return;
        int s=node[l],t=node[l+1];
        int cut=network_flow::dinic(s,t);
        add_edge(s,t,cut);
        int cnt1=0,cnt2=0;
        for(int i=l; i<=r; i++) {
            if(network_flow::deep[node[i]]) tmp1[++cnt1]=node[i];
            else tmp2[++cnt2]=node[i];
        }
        for(int i=l; i<=l+cnt1-1; i++) node[i]=tmp1[i-l+1];
        for(int i=l+cnt1; i<=r; i++) node[i]=tmp2[i-l-cnt1+1];
        build(l,l+cnt1-1);
        build(l+cnt1,r);
    }

    int log2n;
    int deep[maxv];
    int anc[maxv][maxlogv];
    int minl[maxv][maxlogv];
    void dfs(int x,int fa) {
//		printf("dfs on %d\n",x);
        deep[x]=deep[fa]+1;
        for(int i=1; i<=log2n; i++) {
            anc[x][i]=anc[anc[x][i-1]][i-1];
            minl[x][i]=min(minl[x][i-1],minl[anc[x][i-1]][i-1]);
        }
        for(int i=head[x]; i; i=E[i].next) {
            int y=E[i].to;
            if(y!=fa) {
                anc[y][0]=x;
                minl[y][0]=E[i].len;
                dfs(y,x);
            }
        }
    }

    void work() {
        
        sz=1;
        memset(E,0,sizeof(E));
        memset(head,0,sizeof(head));
        log2n=log2(n)+1;
        for(int i=1; i<=n; i++) node[i]=i;
        memset(deep,0,sizeof(deep));
        memset(anc,0,sizeof(anc));
        memset(minl,0,sizeof(minl));
        build(1,n);
//		printf("buildok");
        dfs(1,0);
    }

    int query(int x,int y) {
        int ans=INF;
        if(deep[x]<deep[y]) swap(x,y);
        for(int i=log2n; i>=0; i--) {
            if(deep[anc[x][i]]>=deep[y]) {
                ans=min(ans,minl[x][i]);
                x=anc[x][i];
            }
        }
        if(x==y) return ans;
        for(int i=log2n; i>=0; i--) {
            if(anc[x][i]!=anc[y][i]) {
                ans=min(ans,minl[x][i]);
                ans=min(ans,minl[y][i]);
                x=anc[x][i];
                y=anc[y][i];
            }
        }
        ans=min(ans,minl[x][0]);
        ans=min(ans,minl[y][0]);
        return ans;
    }
}

int cases;
int pc;
int ans[maxv*maxv/2];
int main() {
#ifdef FILE_IO
    freopen("1.in","r",stdin);
#endif
    int u,v,w;
    scanf("%d",&cases);
    while(cases--) {
        memset(network_flow::head,0,sizeof(network_flow::head));
        memset(network_flow::E,0,sizeof(network_flow::E));
        network_flow::sz=1;
        scanf("%d %d",&n,&m);
        for(int i=1; i<=m; i++) {
            scanf("%d %d %d",&u,&v,&w);
            network_flow::add_edge(u,v,w);
            network_flow::add_edge(v,u,w);
        }
        mincut_tree::work();
        pc=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans[++pc]=mincut_tree::query(i,j);	
            }
        }
        sort(ans+1,ans+1+pc);
        scanf("%d",&q);
        for(int i=1; i<=q; i++) {
            scanf("%d",&w);
            printf("%d\n",upper_bound(ans+1,ans+1+pc,w)-ans-1);
        }
        printf("\n");
    }
}


```

