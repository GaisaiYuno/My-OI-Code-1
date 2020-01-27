//��ÿ�����޿��ɵ�(x,y)
//��ôһ�����޾��൱��һ���½�������
//��Ȼ���ཻ�½���������=����������г���
//������ѯ��(A,B)����ѯ�����ߣ���x�Ӵ�С����ɨ���ߣ�����ĳ����ѯ�ʵĵط��͸��´�
//��y��ɢ��֮��dp,dp[i]=max(dp[j]+1), j<=i ���߶���ά��
//��ѯB�����ǲ�ѯ[1,B]��dp���ֵ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300000
#define maxq 300000
using namespace std;
struct segment_tree{
	struct node{
		int l;
		int r;
		int v;
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
	}
	void update(int upos,int val,int pos){
		if(tree[pos].l==tree[pos].r){
			tree[pos].v=val;
			return;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(upos<=mid) update(upos,val,pos<<1);
		else update(upos,val,pos<<1|1);
		push_up(pos);
	}
	int query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].v;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		int ans=0;
		if(L<=mid) ans=max(ans,query(L,R,pos<<1));
		if(R>mid) ans=max(ans,query(L,R,pos<<1|1));
		return ans;
	}
}T;

int n,q;
struct node{
	int x;
	int y;
	int dy; //y����ɢ��������dp 
	int type;//ѯ�ʺ͵����һ�� ��type���֣��������� 
	friend bool operator < (node p,node q){
		if(p.x==q.x){
			if(p.y==q.y) return p.type<q.type;
			else return p.y<q.y; 
		}
		else return p.x>q.x;
	} 
}a[maxn+maxq+5];
int b[maxn+5];
int ans[maxn+5];
int main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		a[i].type=0;
		b[i]=a[i].y;
	}
	for(int i=n+1;i<=n+q;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		a[i].type=i-n;
	}
	sort(b+1,b+1+n);
	int sz=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n+q;i++){
		a[i].dy=upper_bound(b+1,b+1+sz,a[i].y)-b-1;
		//Ϊ�˴���ѯ�ʵı߽��������a[i]<B<a[i+1],Ӧ��ȡi������i+1,���Բ���lower_bound 
//		printf("db:%d %d\n",a[i].dy,lower_bound(b+1,b+1+sz,a[i].y)-b);
	}
	sort(a+1,a+1+n+q);
	T.build(1,sz,1);
	for(int i=1;i<=n+q;i++){
		if(a[i].type==0){
			T.update(a[i].dy,T.query(1,a[i].dy,1)+1,1);
		}else{
			ans[a[i].type]=T.query(1,a[i].dy,1);
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d ",ans[i]);
	}
}
/*
7 3
9 5
3 7
10 6
5 10
2 6
10 10
4 1
10 5
3 5
3 9
*/ 
