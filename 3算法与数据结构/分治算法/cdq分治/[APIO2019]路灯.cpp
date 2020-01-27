#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define maxn 300000 
using namespace std;
typedef long long ll;
int n,m;
int a[maxn+5];
set<int>S;//´æ´¢0µÄÎ»ÖÃ 

int tot;
struct node{
    int a;
    int b;
    int c;
    int type;
    int val;
    int id;
    ll ans;
    node(){
        
    }
    node(int _a,int _b,int _c,int _type,int _val){
        a=_a;
        b=_b;
        c=_c;
        type=_type;
        val=id=ans=0;
        if(_type==2) id=_val;
        else val=_val;
    }
    void print(){
        if(type==1){
            printf("update tim=%d  (%d,%d) val=%d\n",a,b,c,val);
        }else{
            printf("query tim=%d (%d,%d)  id=%d\n",a,b,c,id);
        }
    }
}q[maxn*4+5];
int cmpa(node p,node q){
    if(p.a==q.a){
        if(p.b==q.b) return p.c<q.c;
        else return p.b<q.b;
    }else return p.a<q.a;
}
int cmpb(node p,node q){
    if(p.b==q.b) return p.c<q.c;
    else return p.b<q.b;
}


struct fenwick_tree{
    ll c[maxn+5];
    inline int lowbit(int x){
        return x&(-x);
    }
    inline void update(int pos,int val){
        for(int i=pos;i<=maxn;i+=lowbit(i)) c[i]+=val;
    }
    inline ll query(int pos){
        int ans=0;
        for(int i=pos;i>0;i-=lowbit(i)) ans+=c[i];
        return ans; 
    }
}T;
node tmp[maxn*4+5];
void cdq_divide(ll l,ll r){
    int mid=(l+r)>>1;
    if(l==r) return;
    cdq_divide(l,mid);
    cdq_divide(mid+1,r);
    int ptr=l-1;
    for(int i=mid+1;i<=r;i++){
        while(ptr<mid&&q[ptr+1].b<=q[i].b){
            ptr++;
            if(q[ptr].type==1) T.update(q[ptr].c,q[ptr].val);
        }
        if(q[i].type==2) q[i].ans+=T.query(q[i].c);
    } 
    for(int i=l;i<=ptr;i++) if(q[i].type==1) T.update(q[i].c,-q[i].val);
    int pl=l,pr=mid+1;
    int num=l-1;
    while(pl<=mid&&pr<=r){
        if(cmpb(q[pl],q[pr])) tmp[++num]=q[pl++];
        else tmp[++num]=q[pr++]; 
    }
    while(pl<=mid) tmp[++num]=q[pl++];
    while(pr<=r) tmp[++num]=q[pr++];
    for(int i=l;i<=r;i++) q[i]=tmp[i]; 
} 

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
            q[++tot]=node(i,l,r,2,cntq);
            set<int>::iterator it1=S.upper_bound(l);
            if(*it1>r&&a[l]==1&&a[r]==1){
                ans[cntq]+=i;
//              printf("(%d,%d) + %d\n",l,r,i);
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
                q[++tot]=node(i,l,x,1,-i);
                q[++tot]=node(i,l,r+1,1,i);
                q[++tot]=node(i,x+1,x,1,i);
                q[++tot]=node(i,x+1,r+1,1,-i);
                S.erase(x); 
            }else{//Ï¨Ãð 
                set<int>::iterator pre=S.lower_bound(x);
                pre--; 
                set<int>::iterator nex=S.upper_bound(x);
                l=*pre+1;
                r=*nex-1;
//              printf("for x in [%d,%d], y in [%d,%d],+%d\n",l,x,x,r,i);
                q[++tot]=node(i,l,x,1,i);
                q[++tot]=node(i,l,r+1,1,-i);
                q[++tot]=node(i,x+1,x,1,-i);
                q[++tot]=node(i,x+1,r+1,1,i);
                S.insert(x);
            }
        }   
    }
//  for(int i=1;i<=tot;i++) q[i].print(); 
    sort(q+1,q+1+tot,cmpa);
    cdq_divide(1,tot);
    for(int i=1;i<=tot;i++){
        if(q[i].type==2) ans[q[i].id]+=q[i].ans;
    }
    for(int i=1;i<=cntq;i++) printf("%lld\n",ans[i]);
}
