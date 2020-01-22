#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	int ans;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d",int(a/10*2)+int(b/10*3)+int(c/10*5));
	fclose(stdin);fclose(stdout);
	return 0;
	
}
