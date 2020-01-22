#include<iostream>
#include<fstream>
using namespace std;
int a,b,c,s;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	s=(a/10*2)+(b/10*3)+(c/10*5);
	cout<<s<<endl;
	return 0;
}
