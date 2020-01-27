//https://www.luogu.org/problemnew/show/P3437
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000
using namespace std;
int n,m,q;

struct treey{
	struct node{
		int val;
		int mark;//Ϊ�˽�ʡ�ڴ棬���ü�¼l,r 
	}tree[maxn*4+5];
	void update(int L,int R,int v,int l,int r,int pos){
		tree[pos].val=max(tree[pos].val,v);//update ʱ����·�� value ����·���Ľڵ㣬ÿ����һ���ڵ� �൱��push_up 
		if(L<=l&&R>=r){
			tree[pos].mark=max(tree[pos].mark,v);
			return;
		}
		int mid=(l+r)>>1;
		if(L<=mid) update(L,R,v,l,mid,pos<<1);
		if(R>mid) update(L,R,v,mid+1,r,pos<<1|1);
	}
	int query(int L,int R,int l,int r,int pos){
		if(L<=l&&R>=r){
			return tree[pos].val;
		}
		int mid=(l+r)>>1;
		int ans=tree[pos].mark;//��ǲ����ƣ�����һ·�͵�ǰ���ȡmax 
		if(L<=mid) ans=max(ans,query(L,R,l,mid,pos<<1));
		if(R>mid) ans=max(ans,query(L,R,mid+1,r,pos<<1|1));
		return ans;
	}
};

struct treex{
	struct node{
		treey val;
		treey mark;
	}tree[maxn*4+5];
	void update(int xl,int xr,int yl,int yr,int v,int l,int r,int pos){
		tree[pos].val.update(yl,yr,v,1,m,1);
		if(xl<=l&&xr>=r){
			tree[pos].mark.update(yl,yr,v,1,m,1);
			return;
		}
		int mid=(l+r)>>1;
		if(xl<=mid) update(xl,xr,yl,yr,v,l,mid,pos<<1);
		if(xr>mid) update(xl,xr,yl,yr,v,mid+1,r,pos<<1|1);
	}
	int query(int xl,int xr,int yl,int yr,int l,int r,int pos){
		if(xl<=l&&xr>=r){
			return tree[pos].val.query(yl,yr,1,m,1);
		}
		int mid=(l+r)>>1;
		int ans=tree[pos].mark.query(yl,yr,1,m,1);//��ǲ����ƣ�����һ·�͵�ǰ���ȡmax 
		if(xl<=mid) ans=max(ans,query(xl,xr,yl,yr,l,mid,pos<<1));
		if(xr>mid) ans=max(ans,query(xl,xr,yl,yr,mid+1,r,pos<<1|1));
		return ans;
	}
}T; 

int main(){
	int d,s,h,x,y;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d %d %d %d",&d,&s,&h,&x,&y);
		x++;//����Ĭ�ϴ�1��ʼ������������0������Ҫ+1 
		y++;
		int ans=T.query(x,x+d-1,y,y+s-1,1,n,1);
		T.update(x,x+d-1,y,y+s-1,ans+h,1,n,1);
	}
	printf("%d\n",T.query(1,n,1,m,1,n,1));
} 
