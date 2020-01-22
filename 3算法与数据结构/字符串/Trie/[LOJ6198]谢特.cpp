#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 500000
#define maxlogn 20
#define maxlogv 32
using namespace std;
int n;
int a[maxn+5];
char str[maxn+5];

void rsort(int *ans,int *fi,int *se,int n,int m){
    static int buck[maxn+5];
    for(int i=0;i<=m;i++) buck[i]=0;
    for(int i=1;i<=n;i++) buck[fi[i]]++;
    for(int i=1;i<=m;i++) buck[i]+=buck[i-1];
    for(int i=n;i>=1;i--) ans[buck[fi[se[i]]]--]=se[i];
}
int sa[maxn+5],rk[maxn+5],height[maxn+5];
void suffix_sort(char *str,int n,int m){
    static int se[maxn+5];
    for(int i=1;i<=n;i++){
        rk[i]=str[i];
        se[i]=i;
    } 
    rsort(sa,rk,se,n,m);
    for(int k=1;k<=n;k*=2){
        int p=0;
        for(int i=n-k+1;i<=n;i++) se[++p]=i;
        for(int i=1;i<=n;i++) if(sa[i]>k) se[++p]=sa[i]-k;
        rsort(sa,rk,se,n,m);
        swap(rk,se);
        p=rk[sa[1]]=1;
        for(int i=1;i<=n;i++){
            if(se[sa[i-1]]==se[sa[i]]&&se[sa[i-1]+k]==se[sa[i]+k]) rk[sa[i]]=p;
            else rk[sa[i]]=++p;
        }
        if(p==n) break;
        m=p;
    }
} 
void get_height(char *str,int n,int m){
    suffix_sort(str,n,m);
    for(int i=1;i<=n;i++) rk[sa[i]]=i;
    int k=0;
    for(int i=1;i<=n;i++){
        if(k) k--;
        int j=sa[rk[i]-1];
        while(str[i+k]==str[j+k]) k++;
        height[rk[i]]=k;
    }
}

struct sparse_table{
    int lg2[maxn+5];
    int f[maxn+5][maxlogn+5];
    void ini(int *a,int n){
        lg2[0]=-1;
        for(int i=1;i<=n;i++) lg2[i]=lg2[i>>1]+1;
        for(int i=1;i<=n;i++) f[i][0]=i;
        for(int j=1;(1<<j)<=n;j++){
            for(int i=1;i+(1<<(j-1))-1<=n;i++){
                if(a[f[i][j-1]]<a[f[i+(1<<(j-1))][j-1]]) f[i][j]=f[i][j-1];
                else f[i][j]=f[i+(1<<(j-1))][j-1];
            }
        }
    }
    int query(int *a,int l,int r){
        int k=lg2[r-l+1];
        if(a[f[l][k]]<a[f[r-(1<<k)+1][k]]) return f[l][k];
        else return f[r-(1<<k)+1][k]; 
    }
}ST;



struct persist_trie{
    int root[maxn+5];
    int sz[maxn*maxlogv+5];
    int ch[maxn*maxlogv+5][2];
    int ptr;
    void insert(int pos,int val){
        register int now=root[pos]=++ptr;
        int last=root[pos-1];
        for(int i=maxlogv-1;i>=0;i--){
            sz[now]=sz[last]+1;
            int k=(val>>i)&1;
            ch[now][k]=++ptr;
            ch[now][k^1]=ch[last][k^1];
            now=ch[now][k];
            last=ch[last][k];
        }
        sz[now]=sz[last]+1;
    }
    int query(int l,int r,int val){
        int now=root[r],last=root[l-1];
        int ans=0;
        for(int i=maxlogv-1;i>=0;i--){
            int k=(val>>i)&1;
            int cnt=sz[ch[now][k^1]]-sz[ch[last][k^1]];
            if(cnt){
                ans=ans<<1|1;
                now=ch[now][k^1];
                last=ch[last][k^1];
            }else{
                ans=ans<<1;
                now=ch[now][k];
                last=ch[last][k];
            }
        }
        return ans;
    }
//  int _merge(int x,int y){
//      if(!x||!y) return x+y;
//      ch[x][0]=_merge(ch[x][0],ch[y][0]);
//      ch[x][1]=_merge(ch[x][1],ch[y][1]);
//      sz[x]+=sz[y];
//      return x;
//  }
//  void merge(int x,int y){
//      root[y]=_merge(root[x],root[y]);
//  }
}Tr;

int ans=0;
int cnt=0;
void solve(int l,int r){
    // printf("[%d,%d]\n",l,r);
    if(l==r) return;
    int mid=ST.query(height,l+1,r);
    if(mid-l<=r-mid+1){
        for(int i=l;i<=mid-1;i++){
            ans=max(ans,height[mid]+Tr.query(mid,r,a[sa[i]]));
            cnt++;
        }
    }else{
        for(int i=mid;i<=r;i++){
            ans=max(ans,height[mid]+Tr.query(l,mid-1,a[sa[i]]));
            cnt++;
        }
    }
    solve(l,mid-1);
    solve(mid,r);
}
int main(){
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    get_height(str,n,128);
    ST.ini(height,n);
    for(int i=1;i<=n;i++) Tr.insert(i,a[sa[i]]);
    solve(1,n);
    printf("len=%d\n",cnt);
    printf("%d\n",ans);
} 
