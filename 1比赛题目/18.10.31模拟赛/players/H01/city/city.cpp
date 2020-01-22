#include <bits/stdc++.h>

using namespace std;

namespace StandardIO {

	template<typename T>
	inline void read (T &x) {
		x=0;T f=1;char c=getchar();
		for (; c<'0'||c>'9'; c=getchar()) if (c=='-') f=-1;
		for (; c>='0'&&c<='9'; c=getchar()) x=x*10+c-'0';
		x*=f;
	}
	template<typename T>
	inline void write (T x) {
		if (x<0) putchar('-'),x=-x;
		if (x>=10) write(x/10);
		putchar(x%10+'0');
	}

}

using namespace StandardIO;

#define int long long
namespace Fate {
	
	const int N=1000100;
	
	int n,m,limit=-1,ans=0,d;
	int a[N],x[N],y[N];
	struct node {
		int l,r,val,tag;
	} tree[N<<2];
	
	inline void pushup (int pos) {
		tree[pos].val=tree[pos<<1].val+tree[pos<<1|1].val;
	}
	inline void pushdown (int pos) {
		if (tree[pos].tag) {
			tree[pos<<1].tag+=tree[pos].tag;
			tree[pos<<1|1].tag+=tree[pos].tag;
			tree[pos<<1].val+=(tree[pos<<1].r-tree[pos<<1].l+1)*tree[pos].tag;
			tree[pos<<1|1].val+=(tree[pos<<1|1].r-tree[pos<<1|1].l+1)*tree[pos].tag;
			tree[pos].tag=0;
		}
	}
	void build (int l,int r,int pos) {
		tree[pos].l=l,tree[pos].r=r;
		if (l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1),build(mid+1,r,pos<<1|1);
	}
	void update (int l,int r,int pos) {
		if (l<=tree[pos].l&&tree[pos].r<=r) {
			tree[pos].val+=(tree[pos].r-tree[pos].l+1);
			tree[pos].tag+=1;
			return;
		}
		pushdown(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if (l<=mid) update(l,r,pos<<1);
		if (mid<r) update(l,r,pos<<1|1);
		pushup(pos);
	}
	int query (int l,int r,int pos) {
		if (l<=tree[pos].l&&tree[pos].r<=r) {
			return tree[pos].val;
		}
		pushdown(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1,ans=0;
		if (l<=mid) ans+=query(l,r,pos<<1);
		if (mid<r) ans+=query(l,r,pos<<1|1);
		return ans;
	}
	struct SA{
		const double delta=0.3;
		
        private:
            double ans=1e18,t;
            inline int calcEnergy(int dist){
            	int tmp=0,ans=0;
				for (register int j=1; j<=n; ++j) {
					if (a[j]+dist>limit) continue;
					if (query(a[j]+dist,a[j]+dist,1)!=0) {
						tmp++;
					}
				}
				if (tmp>=ans) {
					if (tmp==n) {
						return n;
					} else {
						ans=tmp,d=dist;
					}
				}
				tmp=0;
				for (register int j=1; j<=n; ++j) {
					if (a[j]-dist<1) continue;
					if (a[j]-dist>limit) continue;
					if (query(a[j]-dist,a[j]-dist,1)!=0) {
						tmp++;
					}
				}
				if (tmp>=ans) {
					if (tmp==n) {
						return n;
					} else {
						ans=tmp,d=min(d,dist);
					}
				}
				return ans;
            }
            inline void simulateAnneal(){
                int x=ansx;t=5000;
	            while(t>1e-14){
	            	srand((unsigned)time(NULL));
                    int X;
					while (X>limit||X<0) X=x+(rand()-RAND_MAX/2)*t;
                    int now=calcEnergy(X),dist=now-ans;
                    if(dist<0){
                        ansx=x=X,ans=now;
                    }else if(exp(-dist/t)*RAND_MAX>rand())x=X;
                    t*=delta;
                }
            }
            
        public:
            SA(){}
            ~SA(){}
            
            int ansx;
            inline pair<int,int> SimulateAnneal(){
                ansx=limit/n;
				for(register int i=1;i<=2;++i)simulateAnneal();
                return make_pair(ansx,calcEnergy(ansx)); 
            }
    }ljz;

	inline void Stay_Night() {
		read(n),read(m);
		for (register int i=1; i<=n; ++i) {
			read(a[i]);
			limit=max(limit,a[i]);
		}
		for (register int i=1; i<=m; ++i) {
			read(x[i]),read(y[i]);
			limit=max(limit,y[i]);
		}
		build(1,limit,1);
		for (register int i=1; i<=m; ++i) {
			update(x[i],y[i],1);
		}
		if (n<=1000) {
			for (register int i=1; i<=limit; ++i) {
				int tmp=0;
				for (register int j=1; j<=n; ++j) {
					if (a[j]+i>limit) continue;
					if (query(a[j]+i,a[j]+i,1)!=0) {
						tmp++;
					}
				}
				if (tmp>ans) {
					if (tmp==n) {
						write(i),putchar(' '),write(n);
						return;
					} else {
						ans=tmp,d=i;
					}
				}
			}
			for (register int i=1; i<=limit; ++i) {
				int tmp=0;
				for (register int j=1; j<=n; ++j) {
					if (a[j]-i<1) continue;
					if (a[j]-i>limit) continue;
					if (query(a[j]-i,a[j]-i,1)!=0) {
						tmp++;
					}
				}
				if (tmp>=ans) {
					if (tmp==n) {
						write(i),putchar(' '),write(n);
						return;
					} else {
						ans=tmp,d=min(d,i);
					}
				}
			}
			write(d),putchar(' '),write(ans);	
		} else {
			pair<int,int>an=ljz.SimulateAnneal();
			write(an.first),putchar(' '),write(an.second);
		}
	}

}
#undef int

int main () {
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	Fate::Stay_Night();
}

