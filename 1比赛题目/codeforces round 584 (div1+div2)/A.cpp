#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100
using namespace std;
int n;
int a[maxn+5]; 
int mark[maxn+5]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(mark[i]) continue;
		cnt++;
		for(int j=1;j<=n;j++){
			if(a[j]%a[i]==0) mark[j]=1;
		}
	}
	printf("%d\n",cnt);
}

