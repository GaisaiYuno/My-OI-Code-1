#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int N,Q,L,A[1005],S,G;
int main()
{
	int i,j;
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&N,&Q);
	for(i=0;i<=N-1;i++)
		scanf("%d",&A[i]);
	sort(A,A+N);
	for(i=0;i<=Q-1;i++)
	{
		scanf("%d%d",&L,&S);
		G=pow(10,L);
		for(j=0;j<=N-1;j++)
			if(A[j]%G==S)
			{
				printf("%d\n",A[j]);
				break;
			}
		if(j==N)
			printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
