#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
int A=0,B=0,C=0,s=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
    scanf("%d %d %d",&A,&B,&C);
    s=A/5+B*3/10+C/2;
    printf("%d",s);
	return 0;
}

