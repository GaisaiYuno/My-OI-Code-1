#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,ans;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	ans=a/10*2+b/10*3+c/10*5;
	cout<<ans;
	return 0;
}
