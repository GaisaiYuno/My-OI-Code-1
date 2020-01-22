#include<bits/stdc++.h>
using namespace std;
long long a[1010],n,q;
bool sbxp(long long x,long long y,long long z){
	if(x==y)return true;
	long long sx=1,fx=1;
	while((x%sx)!=x){
		sx=sx*10;
		fx++;
	}
	fx--;
	if(fx<z)
	return false;
	sx=10;
	for(long long xx=1;xx<=z;xx++){
		long long p=0,q1=0;
		p=x%sx;
		p=p/(sx/10);
		q1=y%sx;
		q1=q1/(sx/10);
		if(p!=q1)
		return false;
		sx=sx*10;
	}
	return true;
}
long long sbxp2(long long y1,long long z1){
	for(long long ii=1;ii<=n;ii++)
		if(sbxp(a[ii],y1,z1)==true)
		return a[ii];
	long long x=-1;
	return x;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(long long t=1;t<=q;t++){
		long long xp1,xp2;
		cin>>xp1>>xp2;
		cout<<sbxp2(xp2,xp1)<<endl;
	}
}
