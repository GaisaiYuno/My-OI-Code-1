#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(int argv,char *argv[])
{
	ifstream fin(argv[2]);
	ifstream ansin(argv[3]);
	ofstream scrout(argv[5]);
	ofstream logout(argv[6]);
	
	long double a,b,d;
	fin>>a;
	ansin>>b;
	d=fabs(a-b);
	if(d<=1e-6)
	{
		scrout<<5<<endl;
		logout<<"Accepted d="<<d<<endl;
	}
	else if(d<=1e-5)
	{
		scrout<<4.5<<endl;
		logout<<"Unaccepted(90%) d="<<d<<endl;
	}
	else if(d<=1e-4)
	{
		scrout<<4<<endl;
		logout<<"Unaccepted(80%) d="<<d<<endl;
	}
	else if(d<=1e-3)
	{
		scrout<<3<<endl;
		logout<<"Unaccepted(60%) d="<<d<<endl;
	}
	else if(d<=1e-2)
	{
		scrout<<2<<endl;
		logout<<"Unaccepted(40%) d="<<d<<endl;
	}
	else if(d<=1e-1)
	{
		scrout<<1<<endl;
		logout<<"Unaccepted(20%) d="<<d<<endl;
	}
	else
	{
		scrout<<0<<endl;
		logout<<"Totally wrong answer or presentation error"<<endl;
	}
	return 0;
}
