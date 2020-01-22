#include<cstdio>
using namespace std;
int main() {
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	double z,x,q,zf;
	scanf("%lf %lf %lf",&z,&x,&q);
	zf=z*0.2+x*0.3+q*0.5;
	printf("%g",zf);
	return 0;
}
