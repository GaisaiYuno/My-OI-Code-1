#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	long a,b,c;
	cin>>a>>b>>c;
	cout<<a*0.2+b*0.3+c*0.5;
	return 0;
	fclose(stdin);
	fclose(stdout);	
}
