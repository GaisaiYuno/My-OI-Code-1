#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int A,B,C;
	cin>>A>>B>>C;
	cout<<A*0.2+B*0.3+C*0.5;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
