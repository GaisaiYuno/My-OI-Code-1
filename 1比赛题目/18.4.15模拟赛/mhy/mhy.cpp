#include<iostream>
#include<cstdio>
using namespace std;
int m,h,y;
int t1,t2;
long long ans;
int main(){
//	freopen("mhy.in","r",stdin);
//	freopen("mhy.out","w",stdout);
	scanf("%d %d %d",&m,&h,&y);
	if(m%y==0) t1=m/y;
	else t1=m/y+1;
	if(h%y==0) t2=h/y;
	else t2=h/y+1;
	ans=(long long)t1*t2;
	printf("%lld",ans);
}
