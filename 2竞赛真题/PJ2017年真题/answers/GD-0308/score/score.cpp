#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<map>
#include<set>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int sum = a*20/100+b*30/100+c*50/100;
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
