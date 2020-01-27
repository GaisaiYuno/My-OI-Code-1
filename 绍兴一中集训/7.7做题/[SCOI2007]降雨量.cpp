/*
�����ҳ������ȷ����� 
����false��
������������1�����Ҷ˵����ȷ�������м��������������ڵ����Ҷ˵㽵����
������������2������˵����ȷ�������м��������������ڵ�����˵㽵����
������������3�������Ҷ˵���ݶ�ȷ��������˵㽵����С���Ҷ˵㽵���� (X��Ľ�����������Y��)

����maybe:
������������1�������Ҷ˵�֮��������Ҷ˵����֮��ȼ�����ݲ�������Ҳ������ǰ����˵�ĸ��õ��ж����������ķ�����
������������2����˵���ݲ�ȷ��
������������3���Ҷ˵���ݲ�ȷ��

����ж�true: ����������������㣬��ô�϶���truetrue

*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50000 
using namespace std;
int n,m;
int tim[maxn+5],val[maxn+5];

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
	if(l==r){
		tree[pos].v=val[l];
		return; 
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
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

int main(){
	int l,r,s,e; 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&tim[i],&val[i]);
	}
	build(1,n,1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&l,&r);
		if(l>=r) printf("false\n");
		s=lower_bound(tim+1,tim+1+n,l)-tim;
		e=lower_bound(tim+1,tim+1+n,r)-tim;
		bool certain_l=(tim[s]==l);
		bool certain_r=(tim[e]==r);
		if(!certain_l) s--;//����Ĭ�ϲ�ѯ�м����(s+1,e-1),����l��ȷ����ʱ��tim[s]>=l,tim[s]���������м�����У�����s++ 
		if(certain_r&&query(s+1,e-1,1)>=val[e]){
			printf("false\n");
			continue;
		}
		else if(certain_l&&query(s+1,e-1,1)>=val[s]){
			printf("false\n");
			continue;
		}
		else if(certain_l&&certain_r&&val[s]<val[e]){
			printf("false\n");
			continue;
		}
		else if(e-s!=r-l){
			printf("maybe\n");
			continue;
		}else if(!certain_l){
			printf("maybe\n");
			continue;
		}else if(!certain_r){
			printf("maybe\n");
			continue;
		}else{
			printf("true\n");
		}
	}
}
