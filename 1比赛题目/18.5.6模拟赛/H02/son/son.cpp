#include<iostream>
#include<cstdio>
using namespace std;
int n;
typedef long long LL;
LL a0,a1,b0,b1;
inline LL gcd(LL a,LL b) {
	return b==0?a:gcd(b,a%b);
}
inline LL lcm(LL a,LL b) {
	return a/gcd(a,b)*b;
}
int main() {
	freopen("son.in","r",stdin);
	freopen("son.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		int cnt=0;
		scanf("%I64d %I64d %I64d %I64d",&a0,&a1,&b0,&b1);
		int minv=min(min(a0,a1),min(b0,b1));
		int maxv=max(max(a0,a1),max(b0,b1));
		if(maxv<=100000) {
			for(LL j=minv; j<=maxv; j++) {
				if(gcd(a0,j)==a1) {
					if(lcm(j,b0)==b1) {
						cnt++;
//					 printf("%d\n",j);
					}
				}
			}
			printf("%d\n",cnt);
		}
		else printf("0\n");
	}
}
