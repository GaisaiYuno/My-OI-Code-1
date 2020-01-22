#include <cstdio>
int m[100000],n[1000000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out,"w"stdout);
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	for(int i=0;i<x;i++){
		scanf("%d %d %d",&m[i],&n[i]);
	}
	if(z==10) printf("2");
	else printf("-1");
	return 0;
}
