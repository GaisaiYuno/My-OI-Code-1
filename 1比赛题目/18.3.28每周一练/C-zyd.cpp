#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int Size=100003;
struct node {
	int l,r;
	int ind;
} w[Size];
int n,tree[Size];
int ans[Size];
int DavidlovesSelina;
inline bool comp(node a,node b) {
	if(a.r!=b.r)	return a.r>b.r;
	return a.l<b.l;
}
inline int lowbit(int rt) {
	return rt&(-rt);
}
int Query(int rt) {
	int sum=0;
	while(rt) {
		sum+=tree[rt];
		rt-=lowbit(rt);
	}
	return sum;
}
void Update(int rt,int v) {
	while(rt<=DavidlovesSelina) {
		tree[rt]+=v;
		rt+=lowbit(rt);
	}
}
void init() {
	memset(ans,0,sizeof(ans));
	memset(tree,0,sizeof(tree));
	DavidlovesSelina=-1;
	for(int i=1; i<=n; i++) {
		w[i].l=read();
		w[i].r=read();
		w[i].ind=i;
		DavidlovesSelina=max(DavidlovesSelina,w[i].r);
	}
	sort(w+1,w+1+n,comp);
}
int main() {
	while(scanf("%d",&n)==1 && n) {
		init();
		for(int i=1; i<=n; i++) {
			if(w[i].l==w[i-1].l && w[i].r==w[i-1].r) {
				ans[w[i].ind]=ans[w[i-1].ind];
			} else {
				ans[w[i].ind]=Query(w[i].l+1);
			}
			Update(w[i].l+1,1);
		}
		for(int i=1; i<n; i++) {
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans[n]);
	}
	return 0;
}
/*
3
1 2
0 3
3 4
0
*/
/*
3
1 2
1 2
1 2
*/

