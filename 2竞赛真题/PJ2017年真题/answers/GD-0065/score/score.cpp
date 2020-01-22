#include<fstream>
using namespace std;
ifstream fin("score.in");
ofstream fout("score.out");
int main ()
{
	float a,b,c;
	fin>>a>>b>>c;
	a*=0.2;
	b*=0.3;
	c*=0.5;
	fout<<(int)(a+b+c);
	fin.close();
	fout.close();
	return 0;
}
