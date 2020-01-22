#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

//I am quite sure this ain't cool.

int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdin);
	int a,b,c;
	cin>>a>>b>>c;
	a = ceil(0.2 * a);
	b = ceil(0.3 * b);
	c = ceil(0.5 * c);
	cout<<a + b + c;
	
	return 0;
}
