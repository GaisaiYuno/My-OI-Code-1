#include<bits/stdc++.h>
using namespace std;
long long a,b,c,ans=0;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=a/5;
	b=b/10;b=b*3;
	c=c/2;
	ans=a+b+c;
	cout<<ans;
}
