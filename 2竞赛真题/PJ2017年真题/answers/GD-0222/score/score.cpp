#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;double t=0;
	cin>>a>>b>>c;
	t=(double)a*0.2+b*0.3+c*0.5;
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
