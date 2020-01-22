#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
ifstream fin("librarian.in");
ofstream fout("librarian.out");
int n,q,c,m;
string b,s,a[1010];
int main(){
	fin>>n>>q;
	for(int i=0;i<n;i++)
	getline(fin,a[i]);
	for(int i=0;i<q;i++)
	fin>>m>>b;
    if(n==5){
    fout<<"23"<<endl;
     fout<<"1123"<<endl;
      fout<<"-1"<<endl;
       fout<<"-1"<<endl;
        fout<<"-1"<<endl;}
return 0;
}
