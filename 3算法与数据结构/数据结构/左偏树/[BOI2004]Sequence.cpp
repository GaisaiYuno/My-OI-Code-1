//https://www.luogu.org/problemnew/show/P4331 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000005
using namespace std;
struct leftist_tree{
	int cnt=0;
	int l[maxn],r[maxn];
	int v[maxn];
	int dist[maxn];
	int root[maxn];
	int sz[maxn];
	int New(int val){
		v[++cnt]=val;
		sz[cnt]=1;
		return cnt;
	} 
	int _merge(int x,int y){
		if(!x||!y) return x+y;
		if(v[x]<v[y]) swap(x,y);
		r[x]=_merge(r[x],y);
		sz[x]=sz[l[x]]+sz[r[x]]+1;
		if(dist[l[x]]<dist[r[x]]) swap(l[x],r[x]);
		dist[x]=dist[r[x]]+1;
		return x; 
	}
	inline int top(int x){
		return v[x];
	}
	inline int size(int x){
		return sz[x];
	}
	void merge(int x,int y){
		root[x]=_merge(root[x],root[y]);
	}
	void del(int &x){
		x=_merge(l[x],r[x]);
	}
	int count_heap(){
		return cnt;
	}
}T; 
int n;
int a[maxn],b[maxn];
struct segment{
	int l;
	int r;
	int len(){
		return r-l+1;
	}
}s[maxn]; 
int main(){
#ifdef FILE_IO
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]-=i;
	}
	int now=0;
	for(int i=1;i<=n;i++){
		now++;
		T.root[now]=T.New(a[i]);
		//这里不能赋值root[cnt]=cnt
		//因为堆的根和now应该是有对应关系，now--的时候堆根节点的位置也应该--
		//如果不这样写，堆的个数会增加，会MLE 
		s[now].l=s[now].r=i;
		while(now>1&&T.top(T.root[now-1])>T.top(T.root[now])){
			s[now-1].r=s[now].r; 
			T.merge(now-1,now);
			now--;
			while(T.size(T.root[now])*2>s[now].len()+1){
				T.del(T.root[now]);
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=now;i++){
		for(int j=s[i].l;j<=s[i].r;j++){
			b[j]=T.top(T.root[i]);
			ans+=abs(a[j]-b[j]);
			
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++){
		printf("%d ",b[i]+i);
	}
}

