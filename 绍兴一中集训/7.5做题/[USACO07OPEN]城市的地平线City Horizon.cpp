//https://blog.csdn.net/xianpingping/article/details/83032798 
//https://www.luogu.org/problemnew/show/P2061 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
using namespace std;
int n;
struct line{
	int lx;
	int rx;
	int y;
	int type;//1Ϊ�±ߣ�-1Ϊ�ϱ� 
	line(){
		
	}
	line(int _lx,int _rx,int _y,int _type){
		lx=_lx;
		rx=_rx;
		y=_y;
		type=_type;
	}
	friend bool operator < (line p,line q){
		return p.y<q.y;
	}
}a[maxn*2+5];
int sza;
int szb;
int b[maxn*2+5];//������ɢ��x����

struct node{
	int l;
	int r;
	long long sum;
	int cnt;
}tree[maxn*4+5];
void push_up(int pos){
	if(tree[pos].cnt>0){
		tree[pos].sum=b[tree[pos].r+1]-b[tree[pos].l];//�߶����ڵ�[l,r]�洢[b[l],b[r+1])�������ĳ��Ⱥ͸������
	}else{
		tree[pos].sum=tree[pos<<1].sum+tree[pos<<1|1].sum; 
	}
} 
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
}
void update(int L,int R,int v,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		tree[pos].cnt+=v;
		push_up(pos);//ֻ��ѯ���ڵ㣬����push_down 
		return;
	}	
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
	push_up(pos);
}

int main(){
#ifdef DEBUG
	freopen("testdata.in","r",stdin);
#endif
	int l,r,h;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&l,&r,&h);
		a[++sza]=line(l,r,0,1);
		a[++sza]=line(l,r,h,-1);
		b[++szb]=l;
		b[++szb]=r;
	} 
	sort(a+1,a+1+sza);
	sort(b+1,b+1+szb);
	szb=unique(b+1,b+1+szb)-b-1;
	long long ans=0;
	build(1,szb,1);
	for(int i=1;i<sza;i++){
		int l=lower_bound(b+1,b+1+szb,a[i].lx)-b;
		int r=lower_bound(b+1,b+1+szb,a[i].rx)-b-1;//ע��߽磬�߶���Ҷ�ӽڵ�x�洢[b[x],b[x+1])�������ĳ��Ⱥ͸������������Ҫ-1 
		if(l<=r) update(l,r,a[i].type,1);
		ans+=tree[1].sum*(a[i+1].y-a[i].y);
	}
	printf("%lld\n",ans);
}
