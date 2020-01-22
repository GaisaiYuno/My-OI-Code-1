#include <iostream>
#include <fstream>
using namespace std;
int main()
{
ifstream fin("jump.in");
ofstream fout("jump.out");	
	int a[501],b[501],min,n,max,i,ans=2,s=0;
	fin>>n>>max>>min;
	for (i=0;i<n;i++) fin>>a[i]>>b[i];
	for (i=0;i<n;i++) if (b[i]>0) s=s+b[i];
	if (s<min) fout<<-1;
	else
	fout<<ans;
	return 0;
}
