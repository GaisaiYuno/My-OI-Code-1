#include<iostream>
#include<cstdio>
#define maxn 100005 
using namespace std;
int n,m;
struct leftist_tree{
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
		fa[a[x].r]=x;//һ��Ҫ�ڽ���ǰ����r�����򽻻�����ܾ͸��²����� 
		if(a[a[x].r].d>a[a[x].l].d) swap(a[x].l,a[x].r);
		if(a[x].r==0) a[x].d=0;
		else a[x].d=a[a[x].r].d+1;
		return x;
	}
	
	void merge(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y) return;//ע�⣬ͬһ�����ϾͲ��úϲ��ˣ������TLE 
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
	int x,y,cmd;
	scanf("%d %d",&n,&m);
	T.init();
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		T.insert(x);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d %d",&x,&y);
			if(T.count(x)==0||T.count(y)==0) continue;
			if(x==y) continue;
			T.merge(x,y);
		}else{
			scanf("%d",&x);
			if(T.count(x)==0) printf("-1\n");
			else{
				printf("%d\n",T.top(x));
				T.pop(x);
			}
		}
	}
} 
