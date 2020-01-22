#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100
using namespace std;
typedef long long ll;
int t,n,m,k;
int h[maxn+5];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&m,&k);
		ll sum=m;
		for(int i=1;i<=n;i++) scanf("%d",&h[i]); 
		bool flag=true;
		for(int i=1;i<n;i++){
			ll minh=max(h[i+1]-k,0);
			if(h[i]<minh){
				sum-=(minh-h[i]);
				if(sum<0){
					flag=false;
					break;
				} 
			}else{
				sum+=h[i]-minh;
			}
		} 
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
}

