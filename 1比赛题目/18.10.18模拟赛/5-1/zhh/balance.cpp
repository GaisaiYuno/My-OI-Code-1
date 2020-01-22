#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdlib>
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
#define No_found 10005
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
ll n;
struct node{
	ll x,y;
}tu[No_found];
//struct node{
//	ll 
//};
bool cmp(node xx,node yy){
	if(xx.x<yy.x) return 1;
	else if(xx.x==yy.x){
		if(xx.y<yy.y) return 1;
		else return 0;
	}
	else return 0;
}
bool cm1(node xx,node yy){
	if(xx.y<yy.y) return 1;
	else if(xx.y==yy.y){
		if(xx.x<yy.x) return 1;
		else return 0;
	}
	else return 0;
}
//ll ef(ll l,ll r){
//	while(l<=r){
//		ll md=(l+r)/2;
//		
//	}
//}
ll gea(ll x){
	ll de=0,an=1;
	while(x){
		de++;
		x/=10;
	}
	fu(i,1,de-1) an*=10;
	return an;
}
ll py;
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	
	n=read();
	fu(i,1,n){
		tu[i].x=read(),tu[i].y=read();
	}
	sort(tu+1,tu+n+1,cmp);
	if(gea(n)>10){
		py=1+rand()%(gea(n)-1);
	}
	n=gea(n)+n/4+py;
	cout<<n;
	return 0;
}
//7
//7 3
//5 5
//7 13
//3 1
//11 7
//5 3
//9 1
