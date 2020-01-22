#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("score.in");
ofstream fout("score.out");
int main()
{
	double a,b,c;
	fin>>a>>b>>c;
	fout<<((a*0.2)+(b*0.3)+(c*0.5));
	return 0;
}
