/*
For my love Selina
*/
#include<iostream>
#include<cstdio>
#define maxn 2005
using namespace std;
int c,d;
long long f1,f2;
long long a[maxn];
long long sum[maxn];
int main(){
	int l,r;
	scanf("%d %lld %lld %d",&c,&f1,&f2,&d);
	for(int i=1;i<=c;i++){
		scanf("%d %d",&l,&r);
		a[l]++;
		a[r+1]--;
	}
	for(int i=1;i<=d;i++){
		a[i]+=a[i-1];
	}
	for(int i=1;i<=d;i++){
		sum[i]=sum[i-1]+a[i]; 
	}
	for(int i=d;i>=1;i--){
		if(sum[d]-sum[i-1]==f1-f2){
			printf("%d\n",i);
			return 0;
		}
	}
}


