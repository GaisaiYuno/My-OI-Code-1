#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
double a,b,c,ans;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	ans=double(a*0.2)+double(b*0.3)+double(c*0.5);
	cout<<ans;
}
