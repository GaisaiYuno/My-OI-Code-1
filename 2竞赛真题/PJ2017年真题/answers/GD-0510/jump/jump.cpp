#include<bits/stdc++.h>
using namespace std;
long long n,d,k,g=0,i,j,g1=INT_MAX,dp=0,ans,x2;
int x,s,x1;
bool b;
int main(){
    freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%lld%lld%lld",&n,&d,&k);
    scanf("%lld%lld",&x,&s);
    dp=s; 
	g=abs(d-x);
	b=false;
	x1=x;
	ans=dp;
	x2=x1;
	for(i=2;i<=n;i++){
		scanf("%d%d",&x,&s);
		if(ans>=k){
			g1=min(g1,g);
			b=true;
		}
		if(dp>=0){
			dp=dp+s;
			if(ans>dp){
				ans=ans;
			}else ans=dp,x2=x;
			if(d-g<=abs(x-x1)<=d+g) g=g;
		    else g=abs(x1-x);
			x1=x;
		} 
		else{
			if(s>=0){
				dp=ans+s;
				if(d-g<=abs(x-x2)<=d+g) g=g;
		        else g=abs(x2-x);
				if(ans>dp){
				    ans=ans;
			    }else ans=dp,x2=x;
				x1=x;
			}
			if(s<0) continue;
		} 
	}
	if(ans>=k) b=true;
	if(b==true) printf("%lld",g1);
	else printf("-1");
	return 0;
}
