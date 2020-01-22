#include <stdio.h>

#define MAXS 1000

unsigned long dp1[MAXS]={1,1}, dp2[MAXS]={0,1}, dp3[MAXS]={0,1};

int
main( void ){
	int ncas,cas, i, w;

	scanf("%d",&ncas);
	for( cas=1; cas<=ncas; cas++ ){
		scanf("%d",&w);
		for( i=2; i<=w; i++ ){
			dp2[i] = dp2[i-1]+dp1[i-1];
			dp3[i] = dp1[i-1]+dp3[i-2];
			dp1[i] = dp1[i-1]+3*dp1[i-2]+dp3[i-1]+2*dp2[i-2];
		}
		printf( "%d %d\n",cas,dp1[w] );
	}
	return 0;
}
