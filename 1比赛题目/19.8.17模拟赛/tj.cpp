#include<bits/stdc++.h>
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
#define inf 0x7fffffff
#define eps 1e-7
#define zhh 100005
#define mod 1000000000
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
inline void fp(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) fp(x/10);
	putchar(x%10+'0');
}
int n,d,hd,tl,la;
int q[zhh];
double a[zhh],b[zhh];
double ans,s;
struct node{
	double x,y;
}f[zhh];
double xl(node j,node k){
	return (j.y-k.y)/(j.x-k.x);
}
bool pd(int x){
	double l1=xl(f[q[x]],f[q[x+1]]),l2=xl(f[q[x+1]],f[0]);
	if(l1>l2) return 1;
	return 0;
}
int erfen(int l,int r){
	while(l<r){
		int mid=l+r>>1;
		if(pd(mid)){
			l=mid+1;
		}
		else r=mid;
	}
	return l;
}
int main(){
	n=read(),d=read();
	fu(i,1,n){
		scanf("%lf %lf",&a[i],&b[i]);
	}
	fu(i,1,n){
		f[i].x-=s,f[i].y=-i*double(d);
		s+=a[i];
        while(tl>1&&xl(f[i],f[q[tl]])>xl(f[q[tl]],f[q[tl-1]])) --tl;
        q[++tl]=i;
		f[0].x=-s,f[0].y=-i*double(d)-b[i];
		hd=erfen(1,tl);
        ans+=1/xl(f[q[hd]],f[0]);
	}
	la=int(ans+0.5);
	fp(la);
	return 0;
}
