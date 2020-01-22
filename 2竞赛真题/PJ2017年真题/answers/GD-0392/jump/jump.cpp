#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
long long x[500001],s[500001],c[500001],n,d,k,i,j,sum=0,maxi=1;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&s[i]);
		if(s[i]>0) sum+=s[i];
		if(s[i]>s[maxi]) maxi=i;
		c[i]=(c[i-1]>abs(s[i]-s[i-1]-d)?c[i-1]:abs(s[i]-s[i-1]-d));
	}
	if(sum<k){
		cout<<-1<<endl;return 0;
	}
	cout<<c[maxi]<<endl;
	return 0;
}
