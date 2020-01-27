#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10005
using namespace std;
int c,n,m;
int l[maxn],r[maxn],lsh[maxn<<1];
int used[maxn<<1];
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
int bin_search(int L,int R,int a[],int x){
    int l=L,r=R;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]==x) return mid;
        else if(a[mid]>x) r=mid-1;
        else l=mid+1;
    }
    return -1;
}
struct node{
    int l;
    int r;
    int mark;
}tree[maxn<<3];
int ans=0;
void build(int l,int r,int pos){
    tree[pos].l=l;
    tree[pos].r=r;
    tree[pos].mark=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,pos<<1);
    build(mid+1,r,pos<<1|1); 
}
void push_down(int pos){
    if(tree[pos].mark){
        tree[pos<<1].mark=tree[pos<<1|1].mark=tree[pos].mark;
        tree[pos].mark=0;
    } 
}
void update(int L,int R,int l,int r,int pos,int v,int i){
    if(L<=l&&R>=r){
        if(tree[pos].mark==0){
            tree[pos].mark=v;
            if(used[i]==0){
                used[i]=1;
                ans++;
            }
        }
        return;
    }
    push_down(pos);
    int mid=(l+r)>>1;
    if(L<=mid) update(L,R,l,mid,pos<<1,v,i);
    if(R>mid) update(L,R,mid+1,r,pos<<1|1,v,i);
} 
int main(){
    //freopen("test.txt","r",stdin);
    //区间长度10^7,区间数量10^4，用离散化
    //[l1,r1][l2,r2]……[ln,rn]
    //将 l1，r1排序
    //设li为第k1大，ri为第k2大，则[li,ri]->[k1,k2] 
    	c=qread();
        memset(used,0,sizeof(used));
        n=qread();
        for(int i=1;i<=n;i++){
            l[i]=qread();
            r[i]=qread();
            lsh[i]=l[i];
            lsh[i+n]=r[i];
        }
        
        sort(lsh+1,lsh+n*2);
        int m=unique(lsh+1,lsh+n*2)-lsh-1;
        for(int i=1;i<=n;i++){
            int k1=bin_search(1,m,lsh,l[i]);
            int k2=bin_search(1,m,lsh,r[i]);
            l[i]=k1;
            r[i]=k2;
            //printf("%d %d\n",l[i],r[i]);
        } 
        
        ans=0;
        build(1,m,1);
        for(int i=n;i>=1;i--){
            update(l[i],r[i],1,m,1,1,i);
        }
        printf("%d\n",ans);
} 
