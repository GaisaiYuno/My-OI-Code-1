#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main(void)
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,total=0;
	cin>>a>>b>>c;
	total=(a*2)/10+(b*3)/10+(c*5)/10;
	cout<<total;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
