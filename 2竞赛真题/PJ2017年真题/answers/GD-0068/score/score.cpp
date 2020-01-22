#include <iostream>
#include <cstdio>

#define aWeight 0.2
#define bWeight 0.3
#define cWeight 0.5

#define InpF "score.in"
#define OutF "score.out"

using namespace std;

int main()
{

	freopen(InpF,"r",stdin);
	freopen(OutF,"w",stdout);

	int A,B,C;
	scanf("%d%d%d",&A,&B,&C);
	int Ans=A/10*2+B/10*3+C/10*5;
	printf("%d\n",Ans);
	return 0;
}
