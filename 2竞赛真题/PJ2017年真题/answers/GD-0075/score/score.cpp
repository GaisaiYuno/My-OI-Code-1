#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	float a,b,c,ans;
	cin>>a>>b>>c;
	ans=a*0.2+b*0.3+c*0.5;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
