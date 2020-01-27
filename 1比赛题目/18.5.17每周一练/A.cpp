#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long gcd(long long a,long long b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main() {
	int n;
	long long p,q,b;
	scanf("%d",&n);
	while(n--) {
		scanf("%I64d%I64d%I64d",&p,&q,&b);
		int g1=gcd(p,q);
		p/=g1;
		q/=g1;
		while(q!=1&&b!=1) {
			b=gcd(q,b);
			q/=b;
		}
		if(q==1) printf("Finite\n");
		else printf("Infinite\n");
	}

}
