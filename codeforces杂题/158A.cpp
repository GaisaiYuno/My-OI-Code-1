#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 105
using namespace std;
int n,k;
int a[maxn];
int cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	int mina=a[k];
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=mina&&a[i]>0){
			cnt++;
		}
	} 
	printf("%d\n",cnt);
} 
