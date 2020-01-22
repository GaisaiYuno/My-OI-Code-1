#include <iostream>
#include <fstream>
using namespace std;
int main(){
	int a,b,c,t;
	ifstream fin("score.in");
	fin>>a>>b>>c;
	fin.close();
	t=a/5+b*3/10+c/2;
	ofstream fout("score.out");
	fout<<t;
	fout.close();
	return 0;
}
