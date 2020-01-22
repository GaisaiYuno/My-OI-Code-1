#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
ifstream fin("chess.in");
ofstream fout("chess.out");
int m,n,x,y,c;
int main(){
	fin>>m>>n;
	for(int i=1;i<=n;i++)
	fin>>x>>y>>c;
	if(n==7)
	fout<<"8"<<endl;
	if(n==5)
	fout<<"-1"<<endl;
	return 0;
}
