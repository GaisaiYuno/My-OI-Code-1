#include<iostream>
#include<fstream>
using namespace std;
int main(){
	int a,b,c,sum;
	ifstream fin("score.in");
	fin>>a>>b>>c;
	fin.close();
	sum=a/10*2+b/10*3+c/10*5;
	ofstream fout("score.out");
	fout<<sum;
	fout.close();
}
