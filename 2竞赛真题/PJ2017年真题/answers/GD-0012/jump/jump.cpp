#include<fstream>
using namespace std;
int main()
{
	ifstream fin("jump.in");
	ofstream fout("jump.out");
	long long n,d,k,l,y;
	fin>>n>>d>>k;
	for(long long i=1;i<=n;i++)
	 fin>>l>>y;
	fout<<"-1";
	return 0;
}
