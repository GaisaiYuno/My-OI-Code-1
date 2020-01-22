#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	cout<<a*2/10+b*3/10+c*5/10<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
