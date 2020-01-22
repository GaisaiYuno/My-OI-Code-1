#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int a,b,c,x[500005],s[500005],whvalue=0;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>a>>b>>c;
	for(int i=0;i<a;i++)
	{
		cin>>x[i]>>s[i];
		whvalue+=s[i];
	}
	if(whvalue<c) cout<<"-1";
	else cout<<"4";
	fclose(stdin);fclose(stdout);
	return 0;
}
