#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500005
using namespace std;
int n;
long long q[maxn],l[maxn],r[maxn]; 
struct node{
	int l;
	int r;
	int mark;
	long long v;//�洢��ɢ����[l,r]��ʱ�䣬���� 
}tree[maxn<<2];
void push_up(int pos){
	if(tree[pos].mark==0)tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v; 
} 
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1); 
}

void update(int L,int R,int v,int pos){
	if(L==tree[pos].l&&R==tree[pos].r){
		tree[pos].mark+=v;
		if(tree[pos].mark==1){//����1���������� 
			tree[pos].v=q[tree[pos].r+1]-q[tree[pos].l];
			//q[tree[pos].r+1]���õ���ɢ��������Ҷˣ���ɢ������ܳ���r��������ɢ��ǰ��q[l]��q[r]֮�䣩
			//�൱�ڰ�������ɢ������֮��Ĳ���Ҳͳ�ƽ�ȥ�� 
		}else if(tree[pos].mark==0){//����0 ����������䱻���� 
			tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v; 
		}
		return;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(R<=mid){
        update(L,R,v,pos<<1);
    }
    else if(L>mid){
       	update(L,R,v,pos<<1|1);
    }
    else{
        update(L,mid,v,pos<<1);
        update(mid+1,R,v,pos<<1|1);
    }
	push_up(pos);
} 
int main(){
	int cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&l[i],&r[i]);
		q[++cnt]=l[i];
		q[++cnt]=r[i];
	}
	sort(q+1,q+1+cnt);
	cnt=unique(q+1,q+1+cnt)-q-1;
	build(1,cnt,1);
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(q+1,q+cnt+1,l[i])-q;
        r[i]=lower_bound(q+1,q+cnt+1,r[i])-q-1;
//        printf("%d %d\n",l[i],r[i]);
        update(l[i],r[i],1,1);
	}
//	printf("%d\n",tree[1].v);
	long long ans=0;
	for(int i=1;i<=n;i++){
		update(l[i],r[i],-1,1);
//		printf("%d:%d\n",i,tree[1].v);
		ans=max(ans,tree[1].v);
		update(l[i],r[i],1,1);
//		printf("%d:%d\n",i,tree[1].v);
	}
	printf("%lld\n",ans);
}
/*
3
1 5
6 9
3 7
*/ 
