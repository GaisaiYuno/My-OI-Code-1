#include <iostream>
#include <fstream>
using namespace std;
int main()
{
ifstream fin("score.in");
ofstream fout("score.out");	
	double a,b,c,s;
	fin>>a>>b>>c;
	a=a*0.2;
	b=b*0.3;
	c=c*0.5;
	s=a+b+c;
	fout<<s;
	return 0;
}
