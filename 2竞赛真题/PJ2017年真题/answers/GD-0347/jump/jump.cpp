#include<bits/stdc++.h>
using namespace std;
long long maxi,ans,i,n,d,k,g,x,a[99999999],a1[11];
int s;
bool b[500001],b1[11];
int ss(int p,int sum){
	if(sum>=k) {
		ans=sum;
		return 0;
	}
	for(i=d-g>0?d-g:1;i<=d+g;i++) {
		if(p+i<99999999) if(b[p+i]==true) ss(p+i,sum+a[p+i]);
		else if(b1[p+i-99999999]==true) ss(p+i,sum+a1[p+i-99999999]);
	}
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%lld%lld%lld",&n,&d,&k);
	for(i=1;i<=n;i++){
		scanf("%lld%d",&x,&s);
		if(s>0) maxi+=s;
		if(x<99999999){
			a[x]=s;
			b[x]=true;
		}
		else{
			a1[x-99999999]=s;
			b1[x-99999999]=true;
		}
	}
	if(maxi<k) {
		printf("-1");
		return 0;
	}
	while(ans<k){
		ss(0,0);
		if(ans>=k) break;
		g++;
	}
	printf("%lld",g);
	return 0;
}
