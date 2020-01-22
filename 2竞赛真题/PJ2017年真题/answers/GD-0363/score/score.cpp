#include<bits/stdc++.h>
using namespace std;
ifstream fin("score.in");
ofstream fout("score.out");
int a,b,c,d;
int main()
{
	fin>>a>>b>>c;
	d=a/10*2+b/10*3+c/10*5;
	fout<<d;
	return 0;
}
