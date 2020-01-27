//http://119.29.55.79/problem/443
//https://blog.csdn.net/The_OIer/article/details/101314005 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500000
#define maxm 500000
using namespace std;
typedef long long ll;
inline void qread(int& x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	x=x*sign;
} 
inline void qprint(const ll x){
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

int n,m,W,L;
int sz;
ll ans[maxn+5];
struct oper{
	int x;//��ֳ�(0,yl,x,yr)�ľ��� 
	int yl;
	int yr;
	int sign;//�޸��ã������+1����-1 
	int id;//ѯ���ã�ѯ�ʱ�� 
	oper(){
		
	}
	oper(int _x,int _yl,int _yr,int _sign,int _id){
		x=_x;
		yl=_yl;
		yr=_yr;
		sign=_sign;
		id=_id; 
	} 
	friend bool operator < (oper p,oper q){
		return p.x<q.x;
	}
}q[maxn*4+5];

struct segment_tree{
	struct node{
		int l;
		int r;
		int len;//�����ǵĳ��� 
		ll sum;//�����ǵ����
		int markl;
		ll marks; 
		inline int length(){
			return r-l+1;
		} 
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].len=tree[pos<<1].len+tree[pos<<1|1].len;
		tree[pos].sum=tree[pos<<1].sum+tree[pos<<1|1].sum;
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
	}
	void push_down(int pos){
		if(tree[pos].marks){
			tree[pos<<1].marks+=tree[pos].marks;
			tree[pos<<1].sum+=tree[pos].marks*tree[pos<<1].length();
			tree[pos<<1|1].marks+=tree[pos].marks;
			tree[pos<<1|1].sum+=tree[pos].marks*tree[pos<<1|1].length();
			tree[pos].marks=0;
		}
		if(tree[pos].markl){
			tree[pos<<1].markl+=tree[pos].markl;
			tree[pos<<1].len+=tree[pos].markl*tree[pos<<1].length();
			tree[pos<<1|1].markl+=tree[pos].markl;
			tree[pos<<1|1].len+=tree[pos].markl*tree[pos<<1|1].length();
			tree[pos].markl=0;
		}
	}
	void update(int L,int R,int x,int sign,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			tree[pos].markl+=sign;
			tree[pos].len+=sign*tree[pos].length();
			tree[pos].marks+=sign*x;
			tree[pos].sum+=sign*x*tree[pos].length();
			return; 
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,x,sign,pos<<1);
		if(R>mid) update(L,R,x,sign,pos<<1|1);
		push_up(pos);
	}
	pair<int,ll> query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return make_pair(tree[pos].len,tree[pos].sum);
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		pair<int,ll>ans=make_pair(0,0);
		if(L<=mid){
			pair<int,ll>lans=query(L,R,pos<<1);
			ans.first+=lans.first;
			ans.second+=lans.second;
		}
		if(R>mid){
			pair<int,ll>rans=query(L,R,pos<<1|1);
			ans.first+=rans.first;
			ans.second+=rans.second;
		}
		return ans;
	} 
}T;


int main(){
	int x1,y1,x2,y2;
	qread(n);
	qread(m);
	qread(W);
	qread(L); 
	for(int i=1;i<=n;i++){
		qread(x1);
		qread(y1);
		qread(x2);
		qread(y2);
		q[++sz]=oper(x1,y1+1,y2,1,0);
		q[++sz]=oper(x2,y1+1,y2,-1,0);
		//ע�������len*x-sum,����ǰ���ǲ��ֵ�sign��1
		//���о��α߳���(y2-y1),�����߶����ϼ������䳤����(r-l+1),����Ҫ��y1+1 
	}
	for(int i=1;i<=m;i++){
		qread(x1);
		qread(y1);
		qread(x2);
		qread(y2);
		q[++sz]=oper(x1,y1+1,y2,-1,i);
		q[++sz]=oper(x2,y1+1,y2,1,i);
		//�޸�Ҳ��������������������ǰ��Ĳ��ּ�ȥ 
	}
	sort(q+1,q+1+sz);
	T.build(0,L,1);
	for(int i=1;i<=sz;i++){
		if(q[i].id==0) T.update(q[i].yl,q[i].yr,q[i].x,q[i].sign,1);
		else{
			pair<int,ll>res=T.query(q[i].yl,q[i].yr,1);
			ans[q[i].id]+=q[i].sign*(1ll*res.first*q[i].x-res.second);//len*x-sum; 
		}
	}
	for(int i=1;i<=m;i++){
		qprint(ans[i]);
		putchar('\n');
	}
}
