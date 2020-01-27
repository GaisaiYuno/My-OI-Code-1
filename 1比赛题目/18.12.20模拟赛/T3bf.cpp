#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
typedef long long ll;
typedef double db;
int n,m;
int judge_cases() {
	if(n*m<5000000) return 1;
	else return 2;
}


namespace brute_force {
	ll x[maxn];
	ll y[maxn];
	void debug() {
		printf("debug:\n");
		for(int i=1; i<=n; i++) {
			printf("%lld ",x[i]);
		}
		printf("\n");
		for(int i=1; i<=n; i++) {
			printf("%lld ",y[i]);
		}
		printf("\n");
		printf("\n");
	}

	void work() {
		int cmd,l,r;
		ll s,t;
		for(int i=1; i<=n; i++) {
			scanf("%lld",&x[i]);
		}
		for(int i=1; i<=n; i++) {
			scanf("%lld",&y[i]);
		}
		for(int i=1; i<=m; i++) {
			scanf("%d",&cmd);
			if(cmd==2) {
				scanf("%d %d %lld %lld",&l,&r,&s,&t);
				for(int i=l; i<=r; i++) {
					x[i]+=s;
					y[i]+=t;
				}
			} else if(cmd==3) {
				scanf("%d %d %lld %lld",&l,&r,&s,&t);
				for(int i=l; i<=r; i++) {
					x[i]=s+i;
					y[i]=t+i;
				}
			} else {
				scanf("%d %d",&l,&r);
				db up,down,ax,ay;
				db sumx=0,sumy=0;
				up=down=0;
				for(int i=l; i<=r; i++) {
					sumx+=x[i];
					sumy+=y[i];
				}
				ax=sumx/(r-l+1);
				ay=sumy/(r-l+1);
				for(int i=l; i<=r; i++) {
					up+=((db)x[i]-ax)*((db)y[i]-ay);
					down+=((db)x[i]-ax)*((db)x[i]-ax);
				}
				printf("%.10f\n",up/down);
			}
			debug();
		}
	}
}


int main() {
	scanf("%d %d",&n,&m);
	int cmd=judge_cases();
	brute_force::work();
}
