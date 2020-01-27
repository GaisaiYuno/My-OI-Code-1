#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 100000
#define maxlogc 25
#define maxc 1000000 
using namespace std;
int n,m;
int a[maxn+5];

struct segment_tree{
//ÿ���߶���ά��һ����ɫc��λ�ó�������������i��λ����ɫΪc.���߶�����[i,i]Ϊ1 
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
	struct node{
		int	ls;
		int rs;
		int lv;//������˵��Ƿ�Ϊ1 
		int rv;//�����Ҷ˵��Ƿ�Ϊ1 
		int sum;//�ܶ��� 
	}tree[maxn*maxlogc+5];
	int ptr;
	void push_up(int x){
		tree[x].lv=tree[lson(x)].lv;
		tree[x].rv=tree[rson(x)].rv;
		tree[x].sum=tree[lson(x)].sum+tree[rson(x)].sum-(tree[lson(x)].rv==1&&tree[rson(x)].lv==1);
		//�����������Ҳ������������Ϊ1����ô���ο���ƴ��һ�������ģ���-1 
	}
	void update(int &x,int upos,int l,int r){
		if(!x) x=++ptr;
		if(l==r){
			tree[x].lv=tree[x].rv=tree[x].sum=1;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(tree[x].ls,upos,l,mid);
		else update(tree[x].rs,upos,mid+1,r);
		push_up(x);
	}
	int merge(int x,int y,int l,int r){
		if(!x||!y) return x+y;
		if(l==r){
			tree[x].sum|=tree[y].sum;
			tree[x].lv|=tree[y].lv;
			tree[x].rv|=tree[y].rv;
			return x;
		} 
		int mid=(l+r)>>1;
		tree[x].ls=merge(tree[x].ls,tree[y].ls,l,mid);
		tree[x].rs=merge(tree[x].rs,tree[y].rs,mid+1,r);
		push_up(x);
		return x;
	}
}T;
int root[maxc+5];
int main(){
	int cmd,x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		T.update(root[a[i]],i,1,n);
	}
	int ans=0;
	for(int i=1;i<=maxc;i++) ans+=T.tree[root[i]].sum;
	for(int i=1;i<=m;i++){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d %d",&x,&y);
			if(x==y) continue;
			ans-=T.tree[root[x]].sum;
			ans-=T.tree[root[y]].sum;
			root[y]=T.merge(root[y],root[x],1,n);//һ��Ҫдroot[y]= 
			ans+=T.tree[root[y]].sum;
			root[x]=0; //�ǵ�ɾ��x����� 
		}
		else printf("%d\n",ans);
	}
}
