#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500005
using namespace std;
int n;
long long a[maxn]; 
long long ans=0;
long long labs(long long x){
	return x>0?x:-x;
} 
int cmp(int x,int y){
	return x>y;
}
int main(){
	int all_pst=1,all_neg=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		if(a[i]>=0) all_neg=0;
		if(a[i]<0) all_pst=0;
		ans+=labs(a[i]);
	}
	sort(a+1,a+1+n);
	if(n==1){
		printf("%I64d\n",(long long)a[1]);
		return 0;
	}else if(n==2){
		printf("%I64d\n",(long long)a[2]-a[1]); 
		return 0;
	} 
	if(all_pst){
		ans-=2*a[1];
	}else if(all_neg){
		ans-=2*labs(a[n]);
	}else{
	}
	printf("%I64d\n",ans);
}
