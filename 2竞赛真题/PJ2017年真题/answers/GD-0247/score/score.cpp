#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
	int A,B,C,ans;
	ifstream fin("score.in");
	fin>>A>>B>>C;
	ans=A*20/100+B*30/100+C*50/100;
	ofstream fout("score.out");
	fout<<ans;
}
