#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
#define maxn 1000005
#define INF 2147483647
using namespace std;
inline int qread(){
    int x=0,sign=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*sign;
}
struct node{
    int l,r;
    int mark1;
    int mark2;
    int minv;
    int maxv;
    long long sum;
    int len(){
        return r-l+1;
    }
    void add(int tag1){
        mark1+=tag1;
        sum+=(long long)tag1*len();
        minv+=tag1;
        maxv+=tag1;
    }
    void set(int tag1,int tag2){
        mark1=tag1;
        mark2=tag2;
        int tmp=tag1+tag2;
        sum=(long long)tmp*len();
        maxv=tmp;
        minv=tmp;
    }
}tree[maxn<<2];
int a[maxn];
int n, m;
void push_up(int pos){
    tree[pos].sum=(long long)tree[pos<<1].sum+tree[pos<<1|1].sum;
    tree[pos].minv=min(tree[pos<<1].minv,tree[pos<<1|1].minv);
    tree[pos].maxv=max(tree[pos<<1].maxv,tree[pos<<1|1].maxv);
}
void build(int l,int r,int pos){
    tree[pos].l=l;
    tree[pos].r=r;
        tree[pos].mark1=0;
        tree[pos].mark2=-1;   //注意 一定 
    if(l==r){
        tree[pos].sum=tree[pos].minv=tree[pos].maxv=a[l];
    //	tree[pos].mark1=tree[pos].mark2=0;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,pos<<1);
    build(mid+1,r,pos<<1|1);
    push_up(pos);
}
void push_down(int pos){
    if(tree[pos].mark2!=-1){
          tree[pos<<1].set(tree[pos].mark1,tree[pos].mark2);
          tree[pos<<1|1].set(tree[pos].mark1,tree[pos].mark2);
         tree[pos].mark1=0; 
          tree[pos].mark2=-1;   //注意 一定 
    }
 if(tree[pos].mark1){
         tree[pos<<1].add(tree[pos].mark1);
         tree[pos<<1|1].add(tree[pos].mark1);
         tree[pos].mark1=0; 
    }
}
void update_section(int to_l,int to_r,int value,int l,int r,int pos,int upd_type,int i){
    int mid=(l+r)>>1;
    
    if(to_l<=l&&to_r>=r){
        if(upd_type==1){ 
          	tree[pos].add(value);
        } 
        else if(upd_type==2){
            tree[pos].set(0,value);
        }
        return;
    }
    push_down(pos);
    if(to_l<=mid) update_section(to_l,to_r,value,l,mid,pos<<1,upd_type,i);
    if(to_r>mid) update_section(to_l,to_r,value,mid+1,r,pos<<1|1,upd_type,i);
    push_up(pos);
}
long long query(int to_l,int to_r,int l,int r,int pos,int que_type){

    if(to_l<=l&&to_r>=r){
        if(que_type==1)
           return tree[pos].sum;
        if(que_type==2) 
          return tree[pos].minv;
        if(que_type==3) 
          return tree[pos].maxv;
    }
    long long ans1=0;
    int ans2=INF,ans3=0;
    int mid=(l+r)>>1;
    push_down(pos);
    if(to_l<=mid){
        if(que_type==1) ans1+=query(to_l,to_r,l,mid,pos<<1,1);
        if(que_type==2) ans2=min(ans2,(int)query(to_l,to_r,l,mid,pos<<1,2));
        if(que_type==3) ans3=max(ans3,(int)query(to_l,to_r,l,mid,pos<<1,3));
    }
   	if(to_r>mid){
        if(que_type==1) ans1+=query(to_l,to_r,mid+1,r,pos<<1|1,1);
        if(que_type==2) ans2=min(ans2,(int)query(to_l,to_r,mid+1,r,pos<<1|1,2));
        if(que_type==3) ans3=max(ans3,(int)query(to_l,to_r,mid+1,r,pos<<1|1,3));
    }
//	if(ans1==9323||ans2==9323||ans3==9323)
//	{
//		ans1=ans1;
//		ans2=ans2;
//	}
    if(que_type==1) return ans1;
    if(que_type==2) return (long long)ans2;
    if(que_type==3) return (long long)ans3;
}
    int c,dir,ql,qr,v;
int main(){
//	freopen("zydph9.in","r",stdin);
    //freopen("zydph.out","w",stdout);
    //printf("%.2fMB\n",(double)(sizeof(tree)+sizeof(a))/1024/1024);
//	int c,dir,ql,qr,v;
    n=qread();
    m=qread();
    for(int i=1;i<=n;i++) a[i]=qread();
    build(1,n,1);
    for(int i=1;i<=m;i++){
        c=qread();
        if(c==1){
            dir=qread();
            ql=qread();
            qr=qread();
            long long rel=query(ql,qr,1,n,1,dir);
            printf("%lld\n",rel);
    //		printf("%lld\n",query(ql,qr,1,n,1,dir));
        }
        else if(c==2){
            dir=qread();
            ql=qread();
            qr=qread();
            v=qread(); 
            update_section(ql,qr,v,1,n,1,dir,i);
            
        }
    }
    return 0; 
}
