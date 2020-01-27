#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 10
#define maxm 100000
using namespace std;
typedef long long ll;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
} 
inline void qread(ll &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
} 
inline void qprint(int x){
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

int n,m,q;
struct treap{
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
	struct node{
		int ls;
		int rs;
		long long val;
		int cnt;
		int sz;
		int dat;
	}tree[maxm+5];
	int ptr;
	int root;
	void push_up(int x){
		tree[x].sz=tree[x].cnt+tree[lson(x)].sz+tree[rson(x)].sz;
	}
	int New(long long val){
		ptr++;
		tree[ptr].val=val;
		tree[ptr].cnt=tree[ptr].sz=1;
		tree[ptr].dat=rand();
		return ptr;
	}
	void rturn(int &x){
		int y=tree[x].ls;
		tree[x].ls=tree[y].rs;
		tree[y].rs=x;
		x=y;
		push_up(tree[x].rs);
		push_up(y);
	}
	void lturn(int &x){
		int y=tree[x].rs;
		tree[x].rs=tree[y].ls;
		tree[y].ls=x;
		x=y;
		push_up(tree[x].ls);
		push_up(y);
	}
	void insert(int &x,long long val){
		if(!x){
			x=New(val);
			return; 
		}
		if(tree[x].val==val){
			tree[x].cnt++;
			push_up(x);
			return;
		}else if(val<tree[x].val){
			insert(tree[x].ls,val);
			if(tree[x].dat<tree[lson(x)].dat) rturn(x);
		}else{
			insert(tree[x].rs,val);
			if(tree[x].dat<tree[rson(x)].dat) lturn(x);
		}
		push_up(x);
	}
	void del(int &x,long long val){
		if(!x) return;
		if(tree[x].val==val){
			if(tree[x].cnt>1){
				tree[x].cnt--;
				push_up(x);
				return;
			}else{
				if(tree[x].ls||tree[x].rs){
					if(tree[lson(x)].dat>tree[rson(x)].dat||tree[x].rs==0){
						rturn(x);
						del(tree[x].rs,val);
					}else{
						lturn(x);
						del(tree[x].ls,val);
					}
					push_up(x);
				}else x=0;
				return;
			}
		}else if(val<tree[x].val){
			del(tree[x].ls,val);
		}else{
			del(tree[x].rs,val);
		}
		push_up(x);
	}
	int count(int x,long long val){
		if(x==0) return 0;
		if(tree[x].val==val){
			return tree[x].cnt;
		}else if(val<tree[x].val){
			return count(tree[x].ls,val);
		}else{
			return count(tree[x].rs,val);
		} 
	}
};
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

struct point{
	ll x;
	ll y;
	point(){
		
	}
	point(ll _x,ll _y){
		x=_x;
		y=_y;
	}
	friend bool operator == (point p,point q){
		return p.x==q.x&&p.y==q.y;
	}
	friend bool operator < (point p,point q){
		if(p.x==q.x) return p.y<q.y;
		else return p.x<q.x;
	}
};
point a[maxn+5],b[maxm+5];
map<point,int>same;
treap cnt[maxn+5];


int query(ll x,ll y){
	int ans=0;
	bool flag=false;
	if(same.count(point(x,y))) flag=true;
	if(flag) ans+=same[point(x,y)];//正好在(x,y)上的特判 
	for(int i=1;i<=n;i++){
		if(flag){
			cnt[i].del(cnt[i].root,a[i].x*y-a[i].y*x);
		} 
	}
	for(int i=1;i<=n;i++){
		ans+=cnt[i].count(cnt[i].root,a[i].x*y-a[i].y*x);
	}
	return ans;
}
int main(){
	freopen("input.txt","r",stdin); 
//	freopen("laser.in","r",stdin);
//	freopen("laser.ans","w",stdout);
	ll xx,yy;
	qread(n);
	for(int i=1;i<=n;i++){
		qread(a[i].x);
		qread(a[i].y);
		ll g=gcd(a[i].x,a[i].y);
		a[i].x/=g;
		a[i].y/=g; 
	}
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
//	printf("ok1\n");
	qread(m);
	for(int i=1;i<=m;i++){
		qread(b[i].x);
		qread(b[i].y);
		same[b[i]]++;
	}
//	printf("ok1.5\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			printf("%lld %lld %lld %lld\n",a[i].x,b[j].y,a[i].y,b[j].x);
			long long p=a[i].x*b[j].y-a[i].y*b[j].x;
			if(p==441193717374ll){
				p=441193717374ll;
			}
			cnt[i].insert(cnt[i].root,p);
//			cout<<p<<endl;
//			printf("%lld\n",a[i].x*b[j].y-a[i].y*b[j].x);
//			cnt[i][p]++;
			
		}
	}
//	printf("ok2\n");
	qread(q); 
	for(int i=1;i<=q;i++){
		qread(xx);
		qread(yy);
		qprint(query(xx,yy));
		putchar('\n');
	}
}

