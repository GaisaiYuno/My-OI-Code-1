#include<bits/stdc++.h>
using namespace std;
int z,t,mid,a[500001],s[500001],dp[500001],as=0,ps=0,i,j,k,n,d,wxp,l,r;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	a[0]=0;
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i],&s[i]);
		if(s[i]>0){
			as+=s[i];
		}
		ps=max(a[i]-a[i-1],ps);
	}
	if(as<k){
		cout<<-1;
		return 0;
	}
	else{
		cout<<2;
	}
}
