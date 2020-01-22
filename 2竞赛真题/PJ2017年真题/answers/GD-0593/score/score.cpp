#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,score;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a*=2;
	b*=3;
	c*=5;
	score=a+b+c;
	cout<<score/10;
	return 0;
}
