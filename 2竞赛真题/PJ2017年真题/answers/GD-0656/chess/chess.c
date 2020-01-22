#include <stdio.h>
/*
struct Road
{
	int x;
	int y;
};
typedef struct Road Road;

Road road[10000];
int cnt = 0;

int color[100][100];

void look_for()
*/
int main(void)
{
	FILE* pin = fopen("chess.in","r");
	FILE* pout = fopen("chess.out","w");
	int size,n;
	fscanf(pin,"%d%d",&size,&n);
	
	int i,j;
	for(i = 0;i< size;i++)
	{
		for(j = 0;j<size;++j)
		{
			color[i][j] = -1;
		}
	}
	int k1,k2,k3;
	for(i = 0;i<n;i++)
	{
		fscanf(pin,"%d%d%d",&k1,&k2,&k3);
		color[k1-1][k2-1] = k3;
	}
	
	fprintf(pout,"%d",n);
	
	return 0;
}
