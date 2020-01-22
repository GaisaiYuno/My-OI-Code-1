#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("score.in");
ofstream fout("score.out");
int A,B,C,D;
int main(){
	fin>>A>>B>>C;
	D=0.2*A+0.3*B+0.5*C;
	if(A!=B)D=D+1;
	fout<<D;
	return 0;
}
