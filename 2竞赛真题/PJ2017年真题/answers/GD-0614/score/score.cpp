#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int a,b,c,s;
int main()
{    
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
    
	scanf("%d%d%d",&a,&b,&c);
	s=a/10*2+b/10*3+c/10*5;
	printf("%d",s);
	
    return 0;
}
