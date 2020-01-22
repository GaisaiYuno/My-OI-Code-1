#include<cstdio>
using namespace std;
int a,b,c;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",(a*2+b*3+c*5)/10);
	return 0;
}
