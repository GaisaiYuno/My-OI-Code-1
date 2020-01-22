#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int a,b,c;
double sum;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	sum=(a*0.2)+(b*0.3)+(c*0.5);
	cout<<sum<<endl;
	return 0;
}
