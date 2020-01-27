#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cassert>
#define MAXN 500005
using namespace std;
inline int read(){
	char ch=getchar();
	int x=0;
	while (ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int cnt;
double a[MAXN];
inline double calc(int x){
	double sum=a[cnt],maxn=a[cnt];
	for (register int i=1;i<=x;++i){
		sum+=a[i];
		maxn=max(a[i],maxn);
	}
	return maxn-(sum/(double)(x+1));
}
//inline double well(){
//	int l=0,r=cnt;
//	while (l<r){
////		printf("%d %d\n",l,r);
//		int lmid=(l*2+r)/3;
//		int rmid=(l+r*2)/3;
//		double lmans=calc(lmid),rmans=calc(rmid);
//		double lans=calc(l),rans=calc(r);
//		if (lmans>rmans&&rmans>rans){
//			r=lmid;
//		}
//		else if (lans<lmans&&lmans<rmans){
//			l=rmid;
//		}
//		else {
//			l=lmid;
//			r=rmid;
//		}
//	}
////	printf("%d %d\n",l,r);
//	return calc(r);
//}
inline double well(){
	double ans=-0x7fffffff;
	for (register int j=0;j<=cnt;++j){
		ans=max(ans,calc(j));
	}
	return ans;
}
int main(){
	freopen("nmax.in","r",stdin);
	freopen("nmax.out","w",stdout);
	int n=read();
	int lastop=2;
	double lastans=0;
	while (n--){
		int op=read();
		if (op==1){
			a[++cnt]=(double)(read());
		}
		else {
			if (lastop==2){
				printf("%.10f\n",lastans);
			}
			else {
				printf("%.10f\n",lastans=well());
			}
		}
		lastop=op;
	}
}
