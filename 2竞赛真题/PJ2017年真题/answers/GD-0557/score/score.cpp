#include<iostream>
#include<cstdio>
using namespace std;
float hw,test,fe;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>hw>>test>>fe;
	cout<<(int)hw*0.2+test*0.3+fe*0.5<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
