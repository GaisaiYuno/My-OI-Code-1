/*
http://codeforces.com/problemset/problem/720/D
���ַ�������Ϊ�ǲ�ͬ�ģ����ҽ�������ĳ���ϰ������һ�ַ�������࣬ ����һ�ַ������Ҳࡣ
Ҳ����˵�����ַ�������ͬ�ĵ��ҽ���ÿ���ϰ��ﶼ��������������ͬһ�ߡ� 
��Ȼ����������ͬ�ķ��������ǲ���ѡ����ߴ����Եķ������ߵþ����ܵ�(�������߾��������ߣ����������ߵ��Ǹ�������
 Ȼ��Ϳ���DP�ˡ�dp[i][j]ʾ�ߵ�(i, j)�������һ����������ʱ�ķ�����
��(i,j)Ϊһ����ӣ�dp[i][j]=dp[i-1][j]
��(i,j)Ϊ�ϰ� dp[i][j]=0;
��(i,j-1)Ϊ�ϰ������Ͻǣ����Դ����������ٹ��� 
	dp[i][j]=dp[i-1][k] low<=k<=j-1 
	����lowΪi-1����j���µ�һ���ϰ�������һ��
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

set<pair<int,int> >seg;//�洢x����һ�����߶Σ�����������µ�һ���ϰ�������һ�� 

int main(){
	int x1,y1,x2,y2;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		a[++sz]=line(x1,y1,y2,1);
		a[++sz]=line(x2+1,y1,y2,-1);//���Ʋ�֣�ȥ���� 
	}
	T.build(1,m,1);
	T.update(1,1,1,1);//dp[1][1]=1
	sort(a+1,a+1+sz);
	
	seg.insert(make_pair(0,0));
	int now=1;//ɨ���ߣ���ǰɨ�赽�ڼ����߶�
	while(a[now].x==1){
		if(a[now].type==1){
			seg.insert(make_pair(a[now].y1,a[now].y2));
		}
		now++;
	} 
	//�߶���ά������dp[i] 
	for(int i=2;i<=n;i++){
		int j=now;
		while(a[j].x==i){//����dpֵ 
			if(a[j].type==1){
				if(a[j].y2<m){
					pair<int,int> pr=*(--seg.lower_bound(make_pair(a[j].y2+1+1,0)));
					//�ϰ����Ͻ�a[j].y2+1 
					int low=pr.second+1;
					long long tmp=T.query(low,a[j].y2+1,1);
					T.update(a[j].y2+1,a[j].y2+1,tmp,1);
				}
			}
			j++;
		}
		j=now;
		while(a[j].x==i){//ȥ�����߶� 
			if(a[j].type==-1){
				seg.erase(make_pair(a[j].y1,a[j].y2));
			}
			j++;
		}
		while(a[now].x==i){//�����µ��߶� 
			if(a[now].type==1){
				seg.insert(make_pair(a[now].y1,a[now].y2));
				T.update(a[now].y1,a[now].y2,0,1);//dp�����ʼ�� 
			}
			now++;
		}
		///����F[i][j]=F[i-1][j]��Ҫ�ܣ���Ϊ����������ƶ���ֱ�Ӽ̳���һ�������F[i][j]
	}
	pair<int,int> last=*(--seg.end());
	printf("%I64d\n",T.query(last.first+1,m,1)%mod);
}

