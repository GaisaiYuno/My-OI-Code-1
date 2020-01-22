#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
using namespace std;
int t,n;
int a[maxn+5];
struct node {
	int val;
	int id;
	friend bool operator < (node p,node q) {
		if(p.val==q.val) return p.id<q.id;
		else return p.val<q.val;
	}
} b[maxn+5];
int ans[maxn+5];
bool check(int d) {
	int mv1=0,mv2=d;
	for(int i=1;i<=n;i++) ans[i]=0;
	for(int i=1; i<=n; i++) {
		if(a[i]<d) {
			if(a[i]<mv1) return 0;
			ans[i]=1;
			mv1=a[i];
		}else if(a[i]==d){
			if(a[i]==mv2){
				 ans[i]=2;
				 mv2=a[i];
			}
			else{
				ans[i]=1;
				mv1=a[i];
			}
		}else{
			if(a[i]<mv2) return 0;
			ans[i]=2;
			mv2=a[i];
		}
	}
	return 1;
}
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%1d",&a[i]);
		}
		bool flag=0;
		for(int d=0; d<=9; d++) {
			if(check(d)){
				for(int i=1;i<=n;i++) printf("%d",ans[i]);
				printf("\n");
				flag=1;
				break;
			}
		}
		if(!flag) printf("-\n");
	}
}

