#include<iostream>
#include<cstdio>
using namespace std;
long a,b,c,ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	ans=(a*20+b*30+c*50)/100;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
