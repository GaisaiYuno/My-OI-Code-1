#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	float a,b,c;
	float ans=0;
	cin>>a>>b>>c;
	ans+=a*0.2;
	ans+=b*0.3;
	ans+=c*0.5;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
