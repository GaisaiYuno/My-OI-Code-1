#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
	freopen("oceanus_5_kill_2.in","w",stdout);
	srand((int) time(0));
	int n=200000;
	int m=200000;
	int g[300000],h[300000];
	g[1]=5;
	for (int i=2;i<=n/2+1;i++)
		g[i]=1;
	for (int i=n/2+2;i<=n;i++)
		g[i]=3;
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
		printf("%d ",g[i]);
	printf("\n");
	for (int i=1;i<n;i++)
		if (i<=n/2)
			printf("%d %d\n",1,i+1);
		else
			if (i<n-1)
				printf("%d %d\n",i-n/2+1,i+1);
			else
				printf("%d %d\n",rand()%(n/2)+2,n);
	printf("%d\n",m);
	h[1]=5,h[2]=3,h[3]=3,h[4]=3;
	for (int i=5;i<=n;i++)
		h[i]=1;
	for (int i=1;i<=m;i++)
		printf("%d ",h[i]);
	return 0;
}
