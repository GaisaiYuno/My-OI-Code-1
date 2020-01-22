#include<bits/stdc++.h>
using namespace std;
int a,b,c,ans=0,aa=0,bb=0,cc=0;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	aa=a*20/100;
	bb=b*30/100;
	cc=c*50/100;
	ans=aa+bb+cc;
	cout<<ans;
	return 0;
}
