#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;
double a,b,c,s;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=a*0.2;
	b=b*0.3;
	c=c*0.5;
	s=a+b+c;
	cout<<s;
	return 0;
}
