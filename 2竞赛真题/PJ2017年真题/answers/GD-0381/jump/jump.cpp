#include<fstream>
using namespace std;
ifstream fin("jump.in");
ofstream fout("jump.out");
int a[500002],s[500002];
int main()
{
	int n=0,d=0,k=0;
	fin>>n>>d>>k;
	for(int i=1;i<=n;i++)
		fin>>a[i]>>s[i];
	fout<<-1;
	return 0;
}
