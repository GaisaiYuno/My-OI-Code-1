#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,s;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>n>>m>>k;
	n=n/10;
	m=m/10;
	k=k/10;
	s=n*2+k*5+m*3;
	cout<<s<<endl;
	return 0;
}
