#include<iostream>
#include<fstream>
using namespace std;
long long A,B,C;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>A>>B>>C;
	cout<<A*0.2+B*0.3+C*0.5;
	return 0;
}
