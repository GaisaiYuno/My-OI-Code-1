#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstdio>
using namespace std;
/*我相信膜蛤出奇迹 */
/*
overall time complexity:
O(n+m)
*/
inline char gc(){
	static char bb[1000000],*s=bb,*t=bb;
	return s==t&&(t=(s=bb)+fread(bb,1,1000000,stdin),s==t)?EOF:*s++;
}
inline int read(){
	register int x=0;register char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=x*10+ch-48,ch=gc();
	return x;
}
int n,m;
int wk[100005];
int cf[1000005];
int ans,ansx;
const double rate=0.97;
int check(int place){
	int ret=0;
	for(int i=1;i<=n;i++)if(wk[i]+place>=0&&wk[i]+place<1000005&&cf[wk[i]+place])ret++;
	return ret;
}
int random(){return rand()*2-RAND_MAX;}
void SA(){
	double temp=2000;
	int x=ansx;
	while(temp>1e-7){
		x=ansx+temp*random();
		x=max(x,-1000005);
		x=min(x,1000005);
		int val=check(x);
		int delta=val-ans;
		if(delta>0){
			ans=val;
			ansx=x;
		}
		if(delta==0){
			if(abs(x)<abs(ansx))ansx=x;
		}
		temp*=rate;
	}
}
void solve(){
	SA();
	SA();
	SA();
	SA();
	SA();
}
int l,r;
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	srand(19260817);
	n=read(),m=read();
	for(int i=1;i<=n;i++)wk[i]=read();
	for(int i=1;i<=m;i++)l=read(),r=read(),cf[l]++,cf[r+1]--;
	for(int i=1;i<1000005;i++)cf[i]+=cf[i-1];
	solve();
	cout<<abs(ansx)<<' '<<ans;
}
