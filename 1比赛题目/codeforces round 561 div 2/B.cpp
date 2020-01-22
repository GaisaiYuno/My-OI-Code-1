#include<iostream>
#include<cstdio>
#define maxn 5005
using namespace std;
int k,n,m;
char vowel[5]= {'a','e','i','o','u'};
char ans[maxn][maxn];
int main() {
	scanf("%d",&k);
	for(int i=5; i<=k; i++) {
		if(k%i==0&&k/i>=5) {
			n=i;
			m=k/i;
			break;
		}
	}
	if(n==0) printf("-1\n");
	else {
		for(int i=0; i<n; i++) {
			int cnt=i%5;
			for(int j=0; j<m; j++) {
				ans[i][j]=vowel[cnt];
				cnt=(cnt+1)%5;
			}
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				printf("%c",ans[i][j]);
			}
		}
	}

}

