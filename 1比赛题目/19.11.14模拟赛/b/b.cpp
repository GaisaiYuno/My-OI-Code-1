#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}
int n,m;
int a[maxn+5];

struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}


int cnt_deep[maxn+5];
int cnt_val[maxn+5];
int deep[maxn+5];
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		}
	}
}
int calc(int root){
	dfs(root,0);
	for(int i=1;i<=n;i++) if(i!=root) cnt_deep[deep[i]]++;
	for(int i=1;i<=n;i++){
		if(i!=root&&cnt_deep[deep[i]]==1) cnt_val[a[i]]++;
	}
	int ans=0;
	for(int i=1;i<=m;i++) if(cnt_val[i]>0) ans++;
	for(int i=1;i<=n;i++) if(i!=root&&cnt_deep[deep[i]]==1) cnt_val[a[i]]--;
	for(int i=1;i<=n;i++) if(i!=root) cnt_deep[deep[i]]--;
	return ans;
}




int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int u,v;
	qread(n);
	qread(m);
	for(int i=1;i<n;i++){
		qread(u);
		qread(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++) qread(a[i]);
	for(int i=1;i<=n;i++){
		qprint(calc(i));
		putchar('\n');
	}
}
/*
5 4
1 2
2 3
3 4
3 5
1 2 1 2 4

7 1
1 2
2 3
3 4
4 5
5 6
6 7
1 1 1 1 1 1 1
*/
