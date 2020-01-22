#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int a,b,c;
	ifstream infile;
	infile.open("score.in");
	ofstream outfile;
	outfile.open("score.out");
	infile >> a >> b >> c;
	int sum=0;
	a=(a*2)/10;b=(b*3)/10;c=(c*5)/10;

	sum=a+b+c;
	outfile << sum;
	infile.close();
	outfile.close(); 
	return 0;
}
