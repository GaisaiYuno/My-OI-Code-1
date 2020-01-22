/*
[El Psy Congroo]
For Selina

Problem:C
Source:Codeforces round 533 (div 2)
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 200005
using namespace std;
int n,k;
int a[maxn]; 
char s[maxn];
int cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%s",s+1);
	int j=1;
	long long ans=0;
	for(int i=1;i<=n;){
		while(j<=n&&s[i]==s[j]) j++;
		j--;
		sort(a+i,a+j+1,cmp);
		for(int u=i;u<=min(j,i+k-1);u++){
			ans+=a[u];
		}
		j++;
		i=j;
	}
	printf("%I64d\n",ans);
}

