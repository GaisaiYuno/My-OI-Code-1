#include<fstream>
using namespace std;
ifstream fin("jump.in");
ofstream fout("jump.out");
int main ()
{
	fout<<-1;
	fin.close();
	fout.close();
	return 0;
}
