#include<iostream>
#include<cstdio>
#define maxn 10005
using namespace std;
int n;
int a[maxn];
int main(){
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int mv=0;
	for(int i=1;i<=n;i++){
		mv=max(mv,a[i]);
		if(mv==i) ans++;
	}
	printf("%d\n",ans);
}

