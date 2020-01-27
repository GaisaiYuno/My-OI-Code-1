#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n,k;
char a[maxn];
int cnt[30];
int main(){
	scanf("%d %d",&n,&k);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		cnt[a[i]-'A'+1]++;
	}
	int ans=n;
	for(int i=1;i<=k;i++){
		ans=min(cnt[i],ans);
	}
	printf("%d\n",ans*k);
} 
