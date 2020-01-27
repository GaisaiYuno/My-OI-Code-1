#include<iostream>
#include<cstdio>
#define maxlog 31
#define maxn 300000
#define maxs 6400000 
using namespace std;



struct persist_trie{
    int sz[maxn*maxlog+5];
    int root[maxn+5];
    int ch[maxn*maxlog+5][2];
    int ptr;
    void insert(int pos,int val){
        int now=root[pos]=++ptr;
        int last=root[pos-1];
        for(int i=maxlog;i>=0;i--){
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
        int now=root[r];
        int last=root[l-1];
        int ans=0;
        for(int i=maxlog;i>=0;i--){
            int k=(val>>i)&1;
            int lsz=sz[ch[now][k^1]]-sz[ch[last][k^1]];
            if(lsz){
                now=ch[now][k^1];
                last=ch[last][k^1];
                ans=ans<<1|1;
            }else{
                now=ch[now][k];
                last=ch[last][k];
                ans=ans<<1;
            }
        }
        return ans;
    }
}T;

int n,m;
int a[maxn+5],sum[maxn+5];
//sum[p]表示前缀异或和
//a[p]^a[p+1]^...a[n]=sum[p-1]^sum[n] 
//问题变成已知x^sum[n],在[l,r]中求一个sum[i],使得sum[i]^(x^sum[n])最大 
int main(){
    int l,r,x;
    char ch[10];
    scanf("%d %d",&n,&m);
    T.insert(0,sum[0]);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]^a[i];
        T.insert(i,sum[i]);
    }
    for(int i=1;i<=m;i++){
    	scanf("%s",ch);
    	if(ch[0]=='A'){
    		scanf("%d",&x);
    		n++;
    		sum[n]=sum[n-1]^x;
    		T.insert(n,sum[n]);
		}else{
			scanf("%d %d %d",&l,&r,&x);
			printf("%d\n",T.query(l-1,r-1,x^sum[n]));
		} 
    }
}
