#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int a,b,c;
int ans=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	ans=(a*2+b*3+c*5)/10;
	printf("%d",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
