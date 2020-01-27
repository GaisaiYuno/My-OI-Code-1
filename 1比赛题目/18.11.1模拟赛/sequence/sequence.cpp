#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
long long a[maxn];
long long b[maxn];
long long sum1,sum2;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		if(b[i]>0) sum1+=b[i];
		else sum2+=(-b[i]);
	}
//	printf("debug:%lld %lld\n",sum1,sum2);
	printf("%lld\n%lld",max(sum1,sum2),abs(sum2-sum1)+1);
} 
//Dedicated to Selina. She is my love forever.
