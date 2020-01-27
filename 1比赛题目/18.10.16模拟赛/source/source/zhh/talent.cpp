#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
#define zhh 1005
using namespace std;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll n,w,ans;
struct node{
	ll w,t;
	double vl;
}nn[255];
double z1,z2;
bool cmp(node xx,node yy){
	return xx.vl>yy.vl;
}
void xx(){
	fu(i,1,n){
		z1+=(double)(nn[i].w),z2+=(double)(nn[i].t);
		if(z1>=w){
			break;
		}
	}
	z2=z2/z1;
	ans=(ll)(z2*1000);
}
int main(){
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	n=read(),w=read();
	fu(i,1,n){
		nn[i].w=read(),nn[i].t=read();
		nn[i].vl=(double)((double)(nn[i].t)/(double)(nn[i].w));
	}
	sort(nn+1,nn+n+1,cmp);
	xx();
	cout<<ans;
	return 0;
}
/*
3 15
20 21
10 11
30 31
*/
