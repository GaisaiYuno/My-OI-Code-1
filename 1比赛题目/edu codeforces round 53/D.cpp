#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200005
using namespace std;
long long n,t;
long long a[maxn];
int main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	long long ans=0;
	while(1){
		long long cnt=0,tot=0;
		for(int i=1;i<=n;i++){
			if(t>=a[i]){
				t-=a[i];
				tot+=a[i];
				cnt++;
			}
		}
		if(cnt==0) break;
		ans+=cnt;
		ans+=cnt*(t/tot);
		t=t%tot;
	} 
	printf("%I64d\n",ans);
} 
