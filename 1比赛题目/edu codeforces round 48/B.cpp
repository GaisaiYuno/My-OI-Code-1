#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1005
using namespace std;
int n,m,q;
char a[maxn],b[maxn];
int sum[maxn];
int cnt[maxn];
int main(){
	int l,r;
	scanf("%d %d %d",&n,&m,&q);
	scanf("%s",a+1);
	scanf("%s",b+1); 
	for(int i=1;i<=n;i++){
		int j;
		for(j=1;j<=m&&i+j-1<=n;j++){
			if(a[i+j-1]!=b[j]) break;
		}
//		printf("%d\n",j);
		if(j==m+1){
			cnt[i]++;
		}
	}
//	for(int i=1;i<=n;i++){
//		printf("%d ",cnt[i]);
//	}
//	printf("\n");
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+cnt[i];
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&l,&r);
		if(r-l+1<m) printf("0\n");
		else printf("%d\n",sum[r-m+1]-sum[l-1]);
	}
} 

