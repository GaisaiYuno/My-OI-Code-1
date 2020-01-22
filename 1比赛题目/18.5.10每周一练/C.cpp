#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int a[maxn]; 
int cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp); 
	bool flag=false;
	for(int i=1;i+2<=n;i++){
		if(a[i]<a[i+1]+a[i+2]){
			flag=true;
			break;
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n"); 
}
