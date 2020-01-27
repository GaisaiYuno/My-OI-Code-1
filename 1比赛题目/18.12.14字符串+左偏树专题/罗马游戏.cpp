#include<iostream>
#include<cstdio>
#define maxn 1000005
using namespace std;
inline void qread(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
//		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}

inline void qprint(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
struct leftiest_tree{
	struct node{
		int l;
		int r;
		int v;
		int d;
	}a[maxn];
	int size=0;
	int del[maxn];
	int fa[maxn];
	void init(){
		a[0].d=-1;
	} 
	
	int find(int x){
		while(fa[x]) x=fa[x];
		return x;
	}
	
	int count(int x){
		return del[x]==0;
	}
	
	void insert(int v){
		size++;
		a[size].v=v;
	}
	
	int _merge(int x,int y){
		if(x==0||y==0) return x+y;
		if(a[x].v>a[y].v) swap(x,y);
		a[x].r=_merge(a[x].r,y);
		fa[a[x].r]=x;//一定要在交换前更新r，否则交换后可能就更新不到了 
		if(a[a[x].r].d>a[a[x].l].d) swap(a[x].l,a[x].r);
		if(a[x].r==0) a[x].d=0;
		else a[x].d=a[a[x].r].d+1;
		return x;
	}
	
	void merge(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y) return;//注意，同一个集合就不用合并了，否则会TLE 
		_merge(x,y);
	}
	
	int pop(int x){
		x=find(x);
		del[x]=1;
		fa[a[x].l]=fa[a[x].r]=0;
		merge(a[x].l,a[x].r);
		return a[x].v;
	}
	
	
}T;

int main(){
//	freopen("7.in","r",stdin);
//	freopen("7.out","w",stdout);
	int x,y;
	char cmd[3];
	scanf("%d",&n);
	T.init();
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		T.insert(x);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='M'){
			scanf("%d %d",&x,&y);
			if(T.del[x]==0||T.del[y]==0) continue;
			if(x==y) continue;
			T.merge(x,y);
		}else{
			scanf("%d",&x);
			if(T.del[x]==0) printf("0\n");
			else{
				qprint(T.pop(x));
//				T.pop(x);
			}
		}
	}
} 
