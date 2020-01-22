#include<cstdio>
#include<cmath>

using namespace std;

int main(){
	freopen ("librarian.in","r",stdin);
	freopen ("librarian.out","w",stdout);
	int n,q,A[1001],h,i,j;
	double w;
	scanf ("%d%d",&n,&q);
	for (int i=0; i<n; i++){
		scanf ("%d",&A[i]);
	}
	sort (A,A+n-1);
	for (i=0; i<q; i++){
		scanf ("%lf%d",&w,&h);
		for (j=0; j<n; j++){
			if (A[j]%(int)(pow(10.0,w))==h){
				printf ("%d\n",A[j]);
				break;
			}
		}
		if (j==n) printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
