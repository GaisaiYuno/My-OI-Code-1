#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c;
main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",a/5+b/10*3+c/2);
	fclose(stdin);
	fclose(stdout);	
}
