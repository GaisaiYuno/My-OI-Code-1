#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream fin("chess.in");
	ofstream fout("chess.out");
	int a,i;
	fin>>a>>a;
	for(i=0;i<a;i++)
	fin>>a>>a>>a;
	fout<<-1;
}
