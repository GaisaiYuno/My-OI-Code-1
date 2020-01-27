//https://www.luogu.org/recordnew/show/18756825
#include<iostream>
#include<cstdio>
#define maxn 100005 
#define maxlogn 18
using namespace std;
int n,m,q;
int a[maxn];
int id[maxn];
int fa[maxn];
int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void merge_set(int x,int y){
    fa[find(x)]=find(y);
}

int ptr=0; 
int root[maxn*maxlogn];
struct node{
    int ls;
    int rs;
    int val;
}tree[maxn*maxlogn]; 
void push_up(int pos){
    tree[pos].val=tree[tree[pos].ls].val+tree[tree[pos].rs].val; 
} 
void insert(int &pos,int l,int r,int val){
    if(pos==0) pos=++ptr;
    if(l==r){
        tree[pos].val=1;
        return;
    }
    int mid=(l+r)>>1;
    if(val<=mid) insert(tree[pos].ls,l,mid,val);
    else insert(tree[pos].rs,mid+1,r,val);
    push_up(pos); 
}
int query(int pos,int l,int r,int val){
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(tree[tree[pos].ls].val>=val) return query(tree[pos].ls,l,mid,val);
    else return query(tree[pos].rs,mid+1,r,val-tree[tree[pos].ls].val);
}
int merge_tree(int x,int y){
    if(!x) return y;
    if(!y) return x;
    tree[x].ls=merge_tree(tree[x].ls,tree[y].ls);
    tree[x].rs=merge_tree(tree[x].rs,tree[y].rs);
    push_up(x);
    return x;
}
int main(){
    int u,v;
    char cmd[2];
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        merge_set(u,v); 
    }
    for(int i=1;i<=n;i++){
        insert(root[find(i)],1,n,a[i]);
        id[a[i]]=i;
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%s",cmd);
        if(cmd[0]=='Q'){
            scanf("%d %d",&u,&v);
            if(tree[root[find(u)]].val<v) printf("-1\n");
            else printf("%d\n",id[query(root[find(u)],1,n,v)]);
        }else{
            scanf("%d %d",&u,&v);
            int fu=find(u),fv=find(v);
            if(fu!=fv){
                root[fv]=merge_tree(root[fu],root[fv]);
                fa[fu]=fv;
            }
            
        }
    }
}

