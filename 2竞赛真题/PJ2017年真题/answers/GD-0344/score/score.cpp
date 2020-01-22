#include<iostream>
#include<cstdio>
#include<fstream>
#include<cmath>
#include<algorithm>
	using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int A=0,B=0,C=0;
	scanf("%d%d%d",&A,&B,&C);
	printf("%.f",A*0.2+B*0.3+C*0.5);
	return 0;
}
