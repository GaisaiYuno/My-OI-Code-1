### 题面

了解奶牛们的人都知道，奶牛喜欢成群结队．观察约翰的N(1≤N≤100000)只奶牛，你会发现她们已经结成了几个“群”．每只奶牛在吃草的时候有一个独一无二的位置坐标Xi，Yi(l≤Xi，Yi≤[1．.10^9]；Xi，Yi∈整数．当满足下列两个条件之一，两只奶牛i和j是属于同一个群的：

  1．两只奶牛的曼哈顿距离不超过C(1≤C≤10^9)，即lXi – xil+IYi – Yil≤C.

  2．两只奶牛有共同的邻居．即，存在一只奶牛k，使i与k，j与k均同属一个群．

​    给出奶牛们的位置，请计算草原上有多少个牛群，以及最大的牛群里有多少奶牛

### 分析

观察$|x_i-x_j|+|y_i-y_j| \leq C$,发现这个式子和x,y都有关，不便维护

我们将点(x,y)变成(X,Y)，其中X=x+y,Y=x-y,那么之后两点间的距离就可以写成$max(|X_i-X_j|,|Y_i-Yj|)​$

设两点坐标为$(x_1,y_1),(x_2,y_2)$,变形之后就变成了$(x_1+y_1,x_1-y_1)(x_2+y_2,x_2-y_2)$，那么$|X_i-X_j|=|(x_1-x_2)+(y_1-y_2)|,|Y_i-Yj|=|(x_1-x_2)+(y_2-y_1)|$。讨论x,y的大小关系即可证明，这里不再赘述



经过上面的转化，我们现在只要保证$max(|X_i-X_j|,|Y_i-Yj|) \leq C$,即$|X_i-X_j| \leq C,|Y_i-Yj| \leq C$

因此我们按X[i]从小到大把点排序，然后维护一个队列，满足$X_{tail}-X_{head} \leq C$，否则就将head出队。那么Y的条件怎么满足呢。我们维护一棵平衡树存储当前队列里的所有点的Y坐标，然后对于新插入的$Y_{tail}$,我们在平衡树里查找它的前驱和后继，判断它们的距离是否<=C,如果是，就将它们的编号合并（用一个并查集）

最后在并查集里查找即可



### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define maxn 100005
#define INF 0x7fffffff
using namespace std;
int n,c;
struct point{
    int x;
    int y;
    int id;
    point(){
        
    }
    point(int xx,int yy,int i){
        x=xx;
        y=yy;
        id=i;
    }
    friend bool operator < (point p,point q){
        return p.x<q.x;
    }
};
point a[maxn],q[maxn*2];
int head=0,tail=0;

struct value{
    int v;
    int id;
    value(){
        
    }
    value(int y,int i){
        v=y;
        id=i;
    }
    friend bool operator < (value p,value q){
        if(p.v==q.v) return p.id<q.id;
        return p.v<q.v;
    } 
    friend bool operator <= (value p,value q){
        return p==q||p<q;
    } 
    friend bool operator > (value p,value q){
        if(p.v==q.v) return p.id>q.id;
        return p.v>q.v;
    } 
    friend bool operator >= (value p,value q){
        return p>q||p==q;
    } 
    friend bool operator == (value p,value q){
        return p.id==q.id&&p.v==q.v;
    }
};
struct treap{
    struct node{
        int ls;
        int rs;
        int cnt;
        int sz;
        value val;
        int dat; 
    }tree[maxn];
    int root;	 
    int ptr;
    int New(value val){
        ptr++;
        tree[ptr].ls=tree[ptr].rs=0;
        tree[ptr].cnt=tree[ptr].sz=1;
        tree[ptr].val=val;
        tree[ptr].dat=rand();
        return ptr;
    }
    void push_up(int x){
        tree[x].sz=tree[tree[x].ls].sz+tree[tree[x].rs].sz+tree[x].cnt;
    }
    void rturn(int &x){
        int y=tree[x].ls;
        tree[x].ls=tree[y].rs;
        tree[y].rs=x;
        x=y;
        push_up(tree[x].rs);
        push_up(x);
    }
    void lturn(int &x){
        int y=tree[x].rs;
        tree[x].rs=tree[y].ls;
        tree[y].ls=x;
        x=y;
        push_up(tree[x].ls);
        push_up(x);
    }
    void insert(int &x,value val){
        if(x==0){
            x=New(val);
            return;
        } 
        if(tree[x].val==val){
            tree[x].cnt++;
            push_up(x);
            return;
        }
        if(val<tree[x].val){
            insert(tree[x].ls,val);
            if(tree[tree[x].ls].dat>tree[x].dat){
                rturn(x);
            } 
        }else{
            insert(tree[x].rs,val);
            if(tree[tree[x].rs].dat>tree[x].dat){
                lturn(x);
            } 
        }
        push_up(x);
    }
    value get_pre(int x,value val){
        if(x==0) return value(-INF,0);
        if(tree[x].val>val) return get_pre(tree[x].ls,val);
        else return max(tree[x].val,get_pre(tree[x].rs,val)); 
    }
    value get_nex(int x,value val){
        if(x==0) return value(INF,0);
        if(tree[x].val<val) return get_nex(tree[x].rs,val);
        else return min(tree[x].val,get_nex(tree[x].ls,val)); 
    }
    void del(int &x,value val){
        if(x==0) return;
        if(tree[x].val==val){
            if(tree[x].cnt>1){ 
                tree[x].cnt--;
                push_up(x);
                return;
            }else{
                if(tree[x].ls||tree[x].rs){
                    if(tree[x].rs==0||tree[tree[x].ls].dat>tree[tree[x].rs].dat){
                        rturn(x);
                        del(tree[x].rs,val);
                    }
                    else{
                        lturn(x); 
                        del(tree[x].ls,val);
                    }
                    push_up(x);
                }else x=0;
                return;
            } 
        }
        if(val<tree[x].val) del(tree[x].ls,val);
        else del(tree[x].rs,val);
        push_up(x);
    }
}T; 

struct DSU{
    int fa[maxn];
    int cnt[maxn];
    void ini(int n){
        for(int i=1;i<=n;i++) fa[i]=i;
    }
    int find(int x){
        if(fa[x]==x) return x;
        else return fa[x]=find(fa[x]);
    }
    void merge(int x,int y){
        int fx=find(x);
        int fy=find(y);
        if(fx==fy) return;
        fa[find(x)]=find(y);
        tot--;
    } 
}S;
int main(){
//	freopen("2.in","r",stdin);
    int x,y;
    scanf("%d %d",&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        a[i].x=x+y;
        a[i].y=x-y;
        a[i].id=i;
    }
    sort(a+1,a+1+n);
    S.ini(n);
    for(int i=1;i<=n;i++){
        while(head<tail&&a[i].x-q[head].x>c){
            T.del(T.root,value(q[head].y,q[head].id));
            head++;
        }
        value pre=T.get_pre(T.root,value(a[i].y,a[i].id));
        value nex=T.get_nex(T.root,value(a[i].y,a[i].id));
        if(pre.v!=-INF&&a[i].y-pre.v<=c) S.merge(a[i].id,pre.id);
        if(nex.v!=INF&&nex.v-a[i].y<=c) S.merge(a[i].id,nex.id);
        q[tail++]=a[i];
        T.insert(T.root,value(a[i].y,a[i].id));
    }
    for(int i=1;i<=n;i++){
        int f=S.find(i);
        S.cnt[f]++;
    }
    int ans=0,tot=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,S.cnt[i]);
    }
    sort(S.fa+1,S.fa+1+n);
    tot=unique(S.fa+1,S.fa+1+n)-S.fa-1;
    printf("%d %d\n",tot,ans);
}

```

