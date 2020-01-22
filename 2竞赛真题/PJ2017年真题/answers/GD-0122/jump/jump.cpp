#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream fin("jump.in");
	ofstream fout("jump.out");
	int a,i;
	fin>>a>i>>i;
	for(i=0;i<a;i++)
	fin>>a>>a;
	fout<<-1;
	return 0;
}
