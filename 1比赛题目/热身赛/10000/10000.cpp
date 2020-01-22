//（G:\c++\资料）初二热身 a
#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 1005
using namespace std;
int a[maxn];
int n;
long long x,y,ans;//连续打卡x天，连续未打卡y天
int main() {
	//freopen("10000.in","r",stdin);
	//freopen("10000.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	x=0;
	y=0;
	ans=0;
	for(int j=1; j<=n; j++) {
		if(a[j]==1) {
			if(y>0) x-=(int)pow(2,y-1);  //减去未打卡的天数
			if(x<0) x=0;
			y=0;
			x++;
			if(x>=1&&x<3) ans+=1;
			if(x>=3&&x<7) ans+=2;
			if(x>=7&&x<30) ans+=3;
			if(x>=30&&x<120) ans+=4;
			if(x>=120&&x<365) ans+=5;
			if(x>=365) ans+=6;
		} else y++;
	}
	cout<<ans;
	return 0;
}
