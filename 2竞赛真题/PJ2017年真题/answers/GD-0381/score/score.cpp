#include<fstream>
using namespace std;
ifstream fin("score.in");
ofstream fout("score.out");
int main()
{
	int a=0,b=0,c=0;
	fin>>a>>b>>c;
	fout<<a*2/10+b*3/10+c*5/10;
	return 0;
}
