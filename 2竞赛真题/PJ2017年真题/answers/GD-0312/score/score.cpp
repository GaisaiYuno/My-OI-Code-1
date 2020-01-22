#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,c;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",a*2/10+b*3/10+c*5/10);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
