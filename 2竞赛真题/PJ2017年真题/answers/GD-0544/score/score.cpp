#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int z,x,k;
	scanf( "%d%d%d",&z,&x,&k );
	cout << z*0.2+x*0.3+k*0.5 << endl;
	return 0;
}
