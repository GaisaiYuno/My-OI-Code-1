#include <iostream>
#include <fstream>
using namespace std;

ifstream is("score.in");
ofstream os("score.out");

int a, b, c;
float d;

int main(){
	is>>a>>b>>c;
	d=a*0.2+b*0.3+c*0.5;
	os<<(int)(d+0.5)<<endl;
	is.close();
	os.close();
	return 0;
}
