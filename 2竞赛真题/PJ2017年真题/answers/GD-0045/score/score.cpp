#include<iostream>
#include<cstdio>
using namespace std;
float a,b,c;int ans;
int main()
{
	
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=a*0.2;b=b*0.3;c=c*0.5;
	ans=a+b+c;
	cout<<ans;
	fclose(stdin);fclose(stdout);
}
