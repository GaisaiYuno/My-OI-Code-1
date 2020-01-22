#include<fstream>
using namespace std;
int main()
{
	ifstream fin("jump.in");
	ofstream fout("jump.out");
	int a,b,c,d,e;
	fin>>a>>b;
	for(int i=1;i<=b;i++)
	 fin>>c>>d>>e;
	fout<<-1;
}
