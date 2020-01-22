#include<iostream>
#include<cstdio>
using namespace std;
main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	cout<<a/5+b/10*3+c/2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
