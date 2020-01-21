#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define maxn 300000 
#define maxlogn 50
using namespace std;
typedef long long ll;
int n,m;
int a[maxn+5];
set<int>S;//´æ´¢0µÄÎ»ÖÃ 


struct dynamic_segment_tree{
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
    struct node{
        int ls;
        int rs;
        ll val;
    }tree[maxn*maxlogn+5];
    int ptr=0;
    void push_up(int x){
        tree[x].val=tree[lson(x)].val+tree[rson(x)].val;
    }
    void update(int &x,int upos,ll uval,int l,int r){
        if(!x) x=++ptr;
        if(l==r){
            tree[x].val+=uval;
            return;
        } 
        int mid=(l+r)>>1;
        if(upos<=mid) update(tree[x].ls,upos,uval,l,mid);
        else update(tree[x].rs,upos,uval,mid+1,r);
        push_up(x);
    }
    ll query(int x,int L,int R,int l,int r){
        if(x==0) return 0;
        if(L<=l&&R>=r) return tree[x].val;
        int mid=(l+r)>>1;
        ll ans=0;
        if(L<=mid) ans+=query(tree[x].ls,L,R,l,mid);
        if(R>mid) ans+=query(tree[x].rs,L,R,mid+1,r);
        return ans;
    }
}T1;
struct fenwick_tree{
    int root[maxn+5];
    inline int lowbit(int x){
        return x&(-x);
    }
    inline void update(int x,int y,ll val){
//      printf("(%d,%d) + %d\n",x,y,val);
        for(int i=x;i<=n+1;i+=lowbit(i)){
            T1.update(root[i],y,val,1,n+1);
        }
    }
    inline ll query(int x,int y){
        ll ans=0;
        for(int i=x;i>0;i-=lowbit(i)){
            ans+=T1.query(root[i],1,y,1,n+1);
        }
        return ans;
    }
}T2;


ll ans[maxn+5];
int main(){
    char cmd[10];
    int l,r;
    int x;
    int cntq=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%1d",&a[i]); 
    for(int i=1;i<=n;i++){
        if(a[i]==0) S.insert(i);
    }
    S.insert(0);
    S.insert(n+1);
    for(int i=1;i<=m;i++){
        scanf("%s",cmd);
        if(cmd[0]=='q'){
            cntq++;
            scanf("%d %d",&l,&r);
            r--;
            set<int>::iterator it1=S.upper_bound(l);
            if(*it1>r&&a[l]==1&&a[r]==1){
                printf("%lld\n",T2.query(l,r)+i);
            }else{
                printf("%lld\n",T2.query(l,r));
            }
        }else{
            scanf("%d",&x);
            a[x]^=1;
            if(a[x]==1){//ÁÁÆð 
                set<int>::iterator pre=S.lower_bound(x);
                pre--; 
                set<int>::iterator nex=S.upper_bound(x);
                l=*pre+1;
                r=*nex-1;
//              printf("for x in [%d,%d], y in [%d,%d],+%d\n",l,x,x,r,-i);
                T2.update(l,x,-i);
                T2.update(l,r+1,i);
                T2.update(x+1,x,i);
                T2.update(x+1,r+1,-i);
                S.erase(x); 
            }else{//Ï¨Ãð 
                set<int>::iterator pre=S.lower_bound(x);
                pre--; 
                set<int>::iterator nex=S.upper_bound(x);
                l=*pre+1;
                r=*nex-1;
                T2.update(l,x,i);
                T2.update(l,r+1,-i);
                T2.update(x+1,x,-i);
                T2.update(x+1,r+1,i);
//              printf("for x in [%d,%d], y in [%d,%d],+%d\n",l,x,x,r,i);
                S.insert(x);
            }
        }   
    }
}
/*
5 2
11011
toggle 3
query 3 4 
*/ 
