#include<cstdio>
using namespace std;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,s;
	scanf("%d %d %d",&a,&b,&c);
	s=(a*20/100)+(b*30/100)+(c*50/100);
	if(s>100) s=100;
	printf("%d",s);
	return 0;
}
