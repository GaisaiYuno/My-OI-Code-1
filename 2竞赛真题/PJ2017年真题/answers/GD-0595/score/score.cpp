#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int main()
{
int a=0,b=0,c=0,d=0;
ifstream fin ("score.in");
ofstream fout ("score.out");
fin>>a>>b>>c;
c=a/10*2+b/10*3+c/10*5;
fout<<c;
return 0;	
}
