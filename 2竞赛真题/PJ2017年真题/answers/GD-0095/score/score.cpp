#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	cout<<a*2/10+b*3/10+c*5/10;
	return 0;
	fclose(stdin);fclose(stdout);
}
