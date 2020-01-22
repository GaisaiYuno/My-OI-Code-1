#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int i,j,k,m,n,a,b,c,s=0;
	cin>>a>>b>>c;
	s=a*20/100+b*30/100+c*50/100;
	cout<<s;
	return 0;
}
