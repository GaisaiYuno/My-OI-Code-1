/*
http://codeforces.com/problemset/problem/720/D
两种方案被认为是不同的，当且仅当存在某个障碍物，它在一种方案的左侧， 在另一种方案的右侧。
也就是说，两种方案是相同的当且仅当每个障碍物都在这两个方案的同一边。 
既然这样，在相同的方案中我们不妨选择最具代表性的方案：走得尽可能低(能往右走尽量往右走，否则往上走的那个方案。
 然后就可以DP了。dp[i][j]示走到(i, j)，且最后一步是向右走时的方案数
当(i,j)为一般格子，dp[i][j]=dp[i-1][j]
当(i,j)为障碍 dp[i][j]=0;
当(i,j-1)为障碍的左上角，可以从下往上走再拐弯 
	dp[i][j]=dp[i-1][k] low<=k<=j-1 
	其中low为i-1列中j往下第一个障碍的上面一格
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#define maxn 1000000
#define mod 1000000007
using namespace std;
struct segment_tree{
	struct node{
		int l;
		int r;
		long long mark;
		long long sum;
		int len(){
			return r-l+1;
		}
	}tree[maxn*4+5];
	void push_up(int x){
		tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
		tree[x].sum%=mod;
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].mark=-1;
		if(l==r){
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	void push_down(int pos){
		if(tree[pos].mark!=-1){
			tree[pos<<1].mark=tree[pos].mark;
			tree[pos<<1].mark%=mod;
			tree[pos<<1|1].mark=tree[pos].mark;
			tree[pos<<1|1].mark%=mod;
			tree[pos<<1].sum=tree[pos].mark*tree[pos<<1].len();
			tree[pos<<1].sum%=mod;
			tree[pos<<1|1].sum=tree[pos].mark*tree[pos<<1|1].len();
			tree[pos<<1|1].sum%=mod;
			tree[pos].mark=-1;
		}
	}
	void update(int L,int R,long long val,int pos){
//		if(pos==1&&val!=0) printf("Modify %d:%I64d\n",L,val);
		if(L<=tree[pos].l&&R>=tree[pos].r){
			tree[pos].mark=val;
			tree[pos].mark%=mod;
			tree[pos].sum=val*tree[pos].len();
			tree[pos].sum%=mod;
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,val,pos<<1);
		if(R>mid) update(L,R,val,pos<<1|1);
		push_up(pos);
	}
	long long query(int L,int R,int pos){
//		if(pos==1) printf("Query [%d,%d]\n",L,R);
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].sum;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		long long ans=0;
		if(L<=mid) ans+=query(L,R,pos<<1);
		if(R>mid)ans+=query(L,R,pos<<1|1);
		return ans;
	}
}T;

int n,m,k;
struct line{
	int x;
	int y1;
	int y2;
	int type;
	line(){
		
	}
	line(int _x,int _y1,int _y2,int _type){
		x=_x;
		y1=_y1;
		y2=_y2;
		type=_type;
	}
	friend bool operator < (line p,line q){
		if(p.x==q.x){
			if(p.y1==q.y1) return p.y2>q.y2;
			else return p.y1>q.y1;
		}else return p.x<q.x;
	}
}a[maxn*2+5];
int sz;

set<pair<int,int> >seg;//存储x坐标一定的线段，方便查找往下第一个障碍的上面一格 

int main(){
	int x1,y1,x2,y2;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		a[++sz]=line(x1,y1,y2,1);
		a[++sz]=line(x2+1,y1,y2,-1);//类似差分，去掉答案 
	}
	T.build(1,m,1);
	T.update(1,1,1,1);//dp[1][1]=1
	sort(a+1,a+1+sz);
	
	seg.insert(make_pair(0,0));
	int now=1;//扫描线，当前扫描到第几个线段
	while(a[now].x==1){
		if(a[now].type==1){
			seg.insert(make_pair(a[now].y1,a[now].y2));
		}
		now++;
	} 
	//线段树维护的是dp[i] 
	for(int i=2;i<=n;i++){
		int j=now;
		while(a[j].x==i){//更新dp值 
			if(a[j].type==1){
				if(a[j].y2<m){
					pair<int,int> pr=*(--seg.lower_bound(make_pair(a[j].y2+1+1,0)));
					//障碍右上角a[j].y2+1 
					int low=pr.second+1;
					long long tmp=T.query(low,a[j].y2+1,1);
					T.update(a[j].y2+1,a[j].y2+1,tmp,1);
				}
			}
			j++;
		}
		j=now;
		while(a[j].x==i){//去除就线段 
			if(a[j].type==-1){
				seg.erase(make_pair(a[j].y1,a[j].y2));
			}
			j++;
		}
		while(a[now].x==i){//加入新的线段 
			if(a[now].type==1){
				seg.insert(make_pair(a[now].y1,a[now].y2));
				T.update(a[now].y1,a[now].y2,0,1);//dp数组初始化 
			}
			now++;
		}
		///至于F[i][j]=F[i-1][j]不要管，因为区间从左到右移动，直接继承上一个区间的F[i][j]
	}
	pair<int,int> last=*(--seg.end());
	printf("%I64d\n",T.query(last.first+1,m,1)%mod);
}

