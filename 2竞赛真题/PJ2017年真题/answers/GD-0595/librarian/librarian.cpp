#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int shu[2000],ren[2000],renn[2000];
int main()
{
ifstream fin ("librarian.in");
ofstream fout ("librarian.out");
int n=0,q=0,happy=10000001,mi=10;
fin>>n>>q;
for(int z=1;z<=n;++z)
fin>>shu[z];
for(int z=1;z<=q;++z)
fin>>renn[z]>>ren[z];
for(int z=1;z<=q;++z)
{
for(int x=1;x<=q;++x)
{
	for(int c=1;c<=renn[z]-1;++c)
	{
		mi*=10;
	}
	
	if(shu[x]%mi==ren[z])
	if(happy>shu[x])
	happy=shu[x];
	mi=10;
	
	
}
	if(happy==10000001)
	fout<<-1;
	else fout<<happy;
	fout<<endl;
	happy=10000001;
}
return 0;
}
