#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;
long long A,B,C,n4;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin >> A >> B >> C ;
	n4=A*0.2+B*0.3+C*0.5;
	cout << n4 << endl ;
	return 0;
}
