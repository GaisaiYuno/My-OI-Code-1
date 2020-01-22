#include<iostream>
#include<fstream>
using namespace std;

float a,b,c;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin >>a >>b >>c;
	cout<<a/100*20+b/100*30+c/100*50;
	
	return 0;
}
