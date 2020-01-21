#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000000
using namespace std;
int n,m;
struct fenwick_tree{	
	int c[maxn+5];
	inline int lowbit(int x){
		return x&(-x);
	}
	void update(int pos,int val){
		for(int i=pos;i<=m;i+=lowbit(i)) c[i]+=val;
	}
	void insert(int x){
		update(x,1);	
	}
	void del(int x){
		update(x,-1);
	}
	int get_rank(int x){
		int ans=0;
		for(int i=x;i>0;i-=lowbit(i)) ans+=c[i];
		return ans;
	} 
	void clear(){
		for(int i=1;i<=m;i++) c[i]=0;
	}
}T;

int p[maxn+5];
int h[maxn+5];
void discrete(int *a,int n){
	static int tmp[maxn+5];
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	sort(tmp+1,tmp+1+n);
	int tn=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=tn;i++) a[i]=lower_bound(tmp+1,tmp+1+tn,a[i])-tmp;
} 

int cnt=0;
int ans[maxn+5];
void kmp(int *a,int n,int *b,int m){
	static int nex[maxn+5]; 
	static int rk[maxn+5];
	for(int i=1;i<=n;i++){
		rk[i]=T.get_rank(a[i]);
		T.insert(a[i]);
	}
	rk[n+1]=m+1;//防止j+1>=n造成的玄学错误 
	
	T.clear();
	nex[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&T.get_rank(a[i])!=rk[j+1]){
			//排名一样，就看作相等 
			for(int k=i-j;k<i-nex[j];k++) T.del(a[k]);
			j=nex[j];
		}
		if(T.get_rank(a[i])==rk[j+1]){
			T.insert(a[i]);
			j++;
		}
		nex[i]=j;
	}
	
	T.clear();
	for(int i=1,j=0;i<=m;i++){
		while(j>0&&T.get_rank(b[i])!=rk[j+1]){
			for(int k=i-j;k<i-nex[j];k++) T.del(b[k]);
			j=nex[j];
		}
		if(T.get_rank(b[i])==rk[j+1]){
			T.insert(b[i]);
			j++;
		}
		if(j==n) ans[++cnt]=i-n+1;
	}
}
int main(){
	int x;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		p[x]=i;
	}
	for(int i=1;i<=m;i++) scanf("%d",&h[i]);
	discrete(h,m);
	kmp(p,n,h,m);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		printf("%d ",ans[i]);
	}
}

