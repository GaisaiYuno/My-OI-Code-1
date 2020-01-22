#include<fstream>
using namespace std;
ifstream cin("score.in");
ofstream cout("score.out");
int main()
{
	long a,b,c;
	cin>>a>>b>>c;
	cout<<a/10*2+b/10*3+c/10*5<<endl;
	return(0);
	cin.close();
	cout.close();
}
