#include<iostream>
#include<cstdio>
using namespace std;
int A,B,C,tem=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	tem=((A*20)/100+(B*30)/100+(C*50)/100);
	printf("%d",tem);
	return 0;
}
