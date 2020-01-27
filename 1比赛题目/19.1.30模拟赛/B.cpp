/*
For my love Selina
*/
#include<iostream>
#include<cstdio>
#define INF 0x7fffffffffffff
using namespace std;
long long cnt1,cnt2,x,y;
long long gcd(  long long a,  long long b){
	return b==0?a:gcd(b,a%b);
}
  long long lcm(  long long a,  long long b){
	return a/gcd(a,b)*b;
}
int check(long long v){
	long long xbei=v/x-v/lcm(x,y);
	long long ybei=v/y-v/lcm(x,y);
	long long other=v-v/x-v/y+v/lcm(x,y);
	if(other>=max(cnt1-ybei,0ll)+max(cnt2-xbei,0ll)) return 1;
	else return 0;
}
int main(){
	cin>>cnt1>>cnt2>>x>>y;
	  long long l=1,r=INF,mid;
	  long long ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<ans;
}
