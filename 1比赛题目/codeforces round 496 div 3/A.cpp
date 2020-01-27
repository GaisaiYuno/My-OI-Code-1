#include<iostream>
#include<cstdio>
#define maxn 10005
using namespace std;
int n;
int a[maxn];
int s[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int cnt=0;
	int first=0;
	a[n+1]=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=a[i+1]){
			cnt++;
			s[cnt]=a[i];
		}
	}
	if(cnt==0){
		cnt++;
		s[cnt]=n;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		printf("%d ",s[i]);
	}
}
