//For my love Selina
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,a,b,w,h;
int check(long long d){
	long long a1=(w/(a+2*d))*(h/(b+2*d));
	long long a2=(w/(b+2*d))*(h/(a+2*d));
	return max(a1,a2)>=n;
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>n>>a>>b>>w>>h;
	long long l=0,r=w;
	long long ans=0;
	long long mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans<<endl;
}
