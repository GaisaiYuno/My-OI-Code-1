#include<fstream>
using namespace std;
ifstream cin ("score.in" ,ios::in );
ofstream cout("score.out",ios::out);
int main()
{
	short a,b,c;
	cin>>a>>b>>c;
	cout<<a/5+b/10*3+c/2;
	cin.clear();
	cout.clear();
	cin.close();
	cout.close();
	return 0;
}
