#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int n,m;
int a[maxn];
int b[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==8){
			if(cnt1<(n-11)/2) cnt1++;
			else b[++m]=a[i];
		}
		if(a[i]!=8){
			if(cnt2<(n-11)/2) cnt2++;
			else b[++m]=a[i];
		}
	}
	
	if(b[1]==8){
		printf("YES");
	}else{
		printf("NO");
	}
}

