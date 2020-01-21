#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define maxn 2000
using namespace std;
int n;
inline int random(int n) {
	return rand()%n+1;
}
inline int random(int l,int r) {
	return l+rand()%(r-l+1);
}

struct node {
	int val;
	int id;
	friend bool operator < (node p,node q) {
		return p.val>q.val;
	}
} a[maxn*3+5];

int main() {
	srand(time(NULL));
	scanf("%d",&n);
	for(int i=1; i<=n*3; i++) {
		scanf("%d",&a[i].val);
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	int sum1=0,sum2=0;
	for(int i=1; i<=n; i++) {
		sum1+=a[i].val;
		sum2+=a[i+n].val;
	}
	while(1) {

		int x=random(1,n);
		int y=random(n+1,n*2);
		sum1=sum1-a[x].val+a[y].val;
		sum2=sum2-a[y].val+a[x].val;
		swap(a[x],a[y]);

		if(sum1>500*n&&sum2>500*n) break;
	}
	for(int i=1; i<=n*3; i++) {
		printf("%d\n",a[i].id);
	}
}

