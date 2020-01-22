#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int Ind=10000000;
int n,q,a[1005],r[1005]={0},k,l,m,minn=Ind;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&l,&m);
		k=int(pow(10,l));
		minn=Ind;
		for(int j=1;j<=n;j++)
			if(a[j]%k==m)
				if(a[j]<minn)r[i]=minn=a[j];
	}
	for(int i=1;i<=q;i++)
		if(r[i])printf("%d\n",r[i]);
		else printf("-1\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
