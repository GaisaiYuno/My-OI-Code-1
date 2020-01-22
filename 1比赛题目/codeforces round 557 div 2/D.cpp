#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#define maxn 100000
#define maxm 200000
using namespace std;
int n,m;
int a[maxm+5],b[maxm+5];
set< pair<int,int> >s;
bool check(int k) { //×ªk¸ñ
	for(int i=1; i<=m; i++) {
		int xx=(a[i]+k)%n;
		int yy=(b[i]+k)%n;
		if(xx==0) xx=n;
		if(yy==0) yy=n;
		if(!s.count(make_pair(min(xx,yy),max(xx,yy)))) return 0;
	}
	return 1;
}

int main() {
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d",&a[i],&b[i]);
		s.insert(make_pair(min(a[i],b[i]),max(a[i],b[i])));
	}
	for(int i=1; i*i<=n; i++) {
		if(n%i==0) {
			if(check(i)) {
				printf("Yes\n");
				return 0;
			}
			if(n/i!=n) {
				if(check(n/i)) {
					printf("Yes\n");
					return 0;
				}
			}
		}
	}
	printf("No\n");
}

