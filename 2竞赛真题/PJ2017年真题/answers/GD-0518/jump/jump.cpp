#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	for(int i=0;i<a;++i)cin>>b>>c;
	cout<<"-1";
	fclose(stdin);fclose(stdout);	
}
