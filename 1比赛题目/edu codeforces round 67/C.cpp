#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1005
using namespace std;
int n,m;
struct node {
	int l;
	int r;
	int t;
	node() {

	}
	node(int L,int R,int T) {
		l=L;
		r=R;
		t=T;
	}
	friend bool operator < (node p,node q) {
		if(p.l==q.l) return p.r<q.r;
		else return p.l<q.l;
	}
} q[maxn+5],t[maxn+5];

int ans[maxn+5];

bool check() {
	for(int i=1; i<=m; i++) {
		if(q[i].t==1) {
			for(int j=q[i].l; j<q[i].r; j++) {
				if(ans[j]>ans[j+1]) return 0; 
			}
		}else{
			bool flag=0;
			for(int j=q[i].l; j<q[i].r; j++) {
				if(ans[j]>ans[j+1]){
					flag=1;
					break;
				}
			}
			if(flag==0) return 0;
		}
	}
	return 1;
}
int main() {
	int tp,l,r;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d",&q[i].t,&q[i].l,&q[i].r);
	}
	sort(q+1,q+1+m);
	q[m+1]=node(1e9,1e9,1);
	int sz=0;
	int lb=0,rb=0;
	for(int i=1; i<=m+1; i++) {
		if(q[i].t==1) {
			if(lb==0&&rb==0) {
				lb=q[i].l;
				rb=q[i].r;
			}

			if(q[i].l<=rb) {
				rb=max(rb,q[i].r);
			} else {
				t[++sz]=node(lb,rb,1);
				lb=q[i].l;
				rb=q[i].r;
			}
		} else {
			if(q[i].l>=lb&&q[i].r<=rb) {
				printf("NO\n");
				return 0;
			}
		}
	}
	int val=1e8;
	for(int i=1; i<=sz; i++) {
		for(int j=t[i].l; j<=t[i].r; j++) {
			ans[j]=j-t[i].l+val;
		}
		val-=(t[i].r-t[i].l+1);
	}

	val=1001;
	for(int i=1; i<=n; i++) {
		if(ans[i]==0) {
			ans[i]=val;
			val--;
		}
	}
	if(!check()) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i=1; i<=n; i++) {
		printf("%d ",ans[i]);
	}
}

