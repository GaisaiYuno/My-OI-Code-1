#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
using namespace std;
ifstream f1;
ifstream f2;
int main(){
	f1.open("myans.txt");
	f2.open("rightans.txt");
	int a,b,c;
	int line=0;
	while(f1>>a){
		line++;
		f2>>b>>c;
		if(a!=b){
			printf("error! read %d expected %d on line %d",a,b,line);
			return 1;
		}
	}
	return 0;
}
