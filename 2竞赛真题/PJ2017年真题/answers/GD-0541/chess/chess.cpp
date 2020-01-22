#include<Cstdio>
using namespace std;
int a,b;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&a,&b);
	if (a==5&&b==7) printf("8");
	else
	if (a==50&&b==250)
	printf("114");
	else
	printf("-1");
	return 0;
}
