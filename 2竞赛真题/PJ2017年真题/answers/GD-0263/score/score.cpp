#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",(a/10*2)+(b/10*3)+(c/10*5));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
