#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a=0,b=0,c=0;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",a/5+b*3/10+c/2);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
