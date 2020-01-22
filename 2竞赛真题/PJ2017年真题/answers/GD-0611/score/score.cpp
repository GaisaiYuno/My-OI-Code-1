#include<cstdio>
using namespace std;
int a,b,c;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",a/5+b/10*3+(c>>1));
	return 0;
}
