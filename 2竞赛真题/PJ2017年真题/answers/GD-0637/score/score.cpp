#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	a=ceil(a*0.2); b=ceil(b*0.3);
	c=ceil(c*0.5);
	cout<<a+b+c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
