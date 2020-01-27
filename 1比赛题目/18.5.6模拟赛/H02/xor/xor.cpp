//CF 691E
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
typedef long long LL;
int n;
LL k;
LL a[maxn];
int is_ok(int x){
	int ans=0;
	for(int i=0;i<=63;i++){
		if((LL)(1<<i)&x) ans++;
	}
	if(ans%3==0) return 1;
	else return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(is_ok(a[i])) ans++;
		}
		printf("%d\n",ans);
	}
} 
