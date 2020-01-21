#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005 
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
	x*=sign; 
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
struct left_tree{
	int cnt;
	int fa[maxn];
	int v[maxn];
	int l[maxn],r[maxn];
	int dis[maxn];
	int find(int x){//查询节点x所在的堆顶编号 
		while(fa[x]!=0) x=fa[x];
		return x;
	}
	void New(int x){//建立一个新的堆x 
		v[++cnt]=x;
		l[cnt]=r[cnt]=0;
		fa[cnt]=0;
		dis[cnt]=0;
	}
	int top(int x){//返回编号x的节点所在堆的堆顶值 
		return v[find(x)];
	}
	int _merge(int x,int y){//合并堆x,堆y 
		if(!x||!y) return x+y;
		if(v[x]>v[y]) swap(x,y);
		r[x]=_merge(r[x],y);
		fa[r[x]]=x;
		if(dis[l[x]]<dis[r[x]]) swap(l[x],r[x]);
		dis[x]=dis[r[x]]+1;
		return x;
	}	
	void merge(int x,int y){//合并x节点，y节点所在的堆 
		x=find(x);
		y=find(y);
		if(x!=y) _merge(x,y);	
	}
	void del(int x){//删除x节点所在的堆顶 
		x=find(x);
		fa[l[x]]=0;
		fa[r[x]]=0;
		merge(l[x],r[x]);
	}
}T;
int kill[maxn];
int main(){
	char cmd[2];
	int x,y,tp;
	qread(n);
	for(int i=1;i<=n;i++){
		qread(x);
		T.New(x);
	}
	qread(m);	
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='M'){
			qread(x);
			qread(y);
			if(kill[x]||kill[y]) continue;
			T.merge(x,y); 
//			printf("debug:\n");
//			for(int i=1;i<=n;i++){
//				printf("%d ",T.find(i));
//			}
//			printf("\n");
		}else{
			qread(x);
			if(kill[x]){
				qprint(0);
				putchar('\n');
			}else{
				tp=T.find(x);
				kill[tp]=1;
				qprint(T.v[tp]);
				putchar('\n');
				T.del(x); 
			}
		}
	} 
}
