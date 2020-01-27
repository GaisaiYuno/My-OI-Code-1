#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxlog 31
#define maxn 400000
using namespace std;


int n,q;
int a[maxn+5];
int sum[maxn+5];

struct Trie{
	int sz;
	int ch[maxn*maxlog+5][2];
	void insert(int v){
		int x=0; 
		for(int i=maxlog-1;i>=0;i--){
			int c=(v>>i)&1;
			if(!ch[x][c]) ch[x][c]=++sz;
			x=ch[x][c];
		} 
	}
	int query(int v){
		int ans=0;
		int x=0;
		for(int i=maxlog-1;i>=0;i--){
			int c=(v>>i)&1;
			if(ch[x][c^1]){
				ans=ans<<1|1;
				x=ch[x][c^1];
			}else{
				ans=ans<<1;
				x=ch[x][c];
			}
		}
		return ans;
	}
	void clear(){
		sz=0;
		memset(ch,0,sizeof(ch));
	}
}T;
int lv[maxn+5],rv[maxn+5];
int maxl[maxn+5],maxr[maxn+5];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
    	sum[i]=sum[i-1]^a[i];
	}
	T.insert(0);
    for(int i=1;i<=n;i++){
    	lv[i]=T.query(sum[i]);
    	T.insert(sum[i]);
    	maxl[i]=max(maxl[i-1],lv[i]);
	}
	T.clear();
	T.insert(0);
	for(int i=n;i>=1;i--){
		rv[i]=T.query(sum[i]);
		T.insert(sum[i]);
		maxr[i]=max(maxr[i+1],rv[i]);
	}
	int ans=0;
	for(int i=1;i<n;i++){
		ans=max(ans,maxl[i]+maxr[i+1]);
	}
	printf("%d\n",ans);
}
