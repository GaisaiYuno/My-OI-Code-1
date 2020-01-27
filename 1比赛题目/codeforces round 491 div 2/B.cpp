#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 105
using namespace std;
int n,sum,esum;
int a[maxn];
int main(){
	scanf("%d",&n);
	sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	} 
	int cnt=0;
	esum=ceil((double)n*4.5);
	if(sum<esum){
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			sum+=(5-a[i]);
			cnt++;
			if(sum>=esum) break;
		}
	}
	printf("%d",cnt);
}

