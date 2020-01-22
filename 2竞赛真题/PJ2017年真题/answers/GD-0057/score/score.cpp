#include<cstdio>
using namespace std;
int a,b,c;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	int score=(a*20/100)+(b*30/100)+(c*50/100);
	printf("%d",score);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
