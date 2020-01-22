#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	float answer;
	cin>>a>>b>>c;
	answer=a*0.2+b*0.3+c*0.5;
	cout<<answer;
	return 0;
}
