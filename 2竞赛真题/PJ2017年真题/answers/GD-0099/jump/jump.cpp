#include<cstdio>
#include<cmath>

using namespace std;

int main(){
	freopen ("jump.in","r",stdin);
	freopen ("jump.out","w",stdout);
	int n,d,k,a,b,maxn=-1,sum=0,x,s,q=0;
	scanf("%d%d%d",&n,&d,&k);
	for (int i=0; i<n; i++){
		scanf ("%d%d",&x,&s);
		if (s>=0){
			q++;
			if (q==1){
				a=x;
			}
			sum+=s;
			b=x;
			if (maxn<b-a) maxn=b-a;
			a=b;
		}
	}
	if (maxn>d) maxn=maxn-d;
	else maxn=0;
	if (sum<k) printf ("-1");
	else printf ("%d",maxn);
	fclose(stdin);
	fclose(stdout);
}
