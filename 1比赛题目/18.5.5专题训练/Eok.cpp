#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int L, R;//target

int input[50005], last[50005], check[1000005];  //last记录每个点的前一个相同的点的位置，不存在记录为-1.
long long sum[50005<<2], ans[200005];

struct Tree {
	int l, r, num;
} a[200005];

bool cmp (Tree x, Tree y) {
	return x.r < y.r;
}

void pushup(int x) {
	sum[x] = sum[x<<1] + sum[x<<1|1];
}

void build(int x, int l, int r) {
	if(l == r) sum[x] = input[l];
	else {
		int m = (l+r) >> 1;
		build(x<<1,l,m);
		build(x<<1|1,m+1,r);
		pushup(x);
	}
}

void update(int x, int l, int r) {
	if(l == r) {
		sum[x] = 0;
		return ;
	}
	int m = (l+r) >> 1;
	if(L <= m) update(x<<1,l,m);
	else update(x<<1|1,m+1,r);
	pushup(x);
}

long long query(int x, int l, int r) {
	if(L <= l && r <= R) return sum[x];
	int m = (l+r) >> 1;
	long long summ = 0;
	if(L <= m) summ += query(x<<1,l,m);
	if(m < R ) summ += query(x<<1|1,m+1,r);
	return summ;
}

inline int read() { //use: read(x);
	int x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(((x<<2)+x)<<1)+ch-'0';
		ch=getchar();
	}
	x*=f;
	return x;
}


int main() {
	t=read();
	while (t--) {
		memset(check, -1, sizeof(check));
		memset(last, -1, sizeof(last));
		n=read();
		for(int i = 1; i <= n; i++) {
			input[i]=read();
			if(check[input[i]] != -1) {
				last[i]=check[input[i]];
				check[input[i]] = i;//更新有效节点
			} else
				check[input[i]] = i;//过过过
		}
		
		//query part 
		m=read();
		for(int i = 1; i <= m; i++) {
			a[i].l=read();
			a[i].r=read();
			a[i].num = i;
		}
		/*
		for(int i = 1; i <= m; i++) {
			printf("%d %d %d",a[i].l,a[i].r,a[i].num);
		}*/
		
		sort(a+1, a+m+1, cmp);//查询右节点排序 
		
		build(1, 1, n);
		int flag = 1;
		for(int i =1; i <= m; i++) {
			for(int j = flag; j <= a[i].r; j++)
				if(last[j] != -1) {
					L=last[j];
					update(1, 1, n);
				}
			L = a[i].l;
			R = a[i].r;
			ans[a[i].num]=query(1, 1, n);
			flag=a[i].r+1;
		}
		
		for(int i=1;i<=m;i++){
			printf("%I64d\n", ans[i]);
		}
	}
	return 0;
}
