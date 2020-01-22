#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int ans,a,b,c;
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	a=a/10;
	b=b/10;
	c=c/10;
	ans=a*2+b*3+c*5;
	cout<<ans;
	return 0;
}
