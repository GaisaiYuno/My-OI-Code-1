#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,s;
	cin>>a>>b>>c;
	s=a/5+b/10*3+c/2;
	cout<<s<<endl;
	return 0;
}
