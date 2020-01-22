#include<algorithm>
#include<fstream>
#include<cstdio>
using namespace std;
int n,q,a[1005],b[1005],c[1005];
bool f;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<q;i++)
		scanf("%d%d",&c[i],&b[i]);
	sort(a,a+n);
	for(int i=0;i<q;i++)
	{
		int s=1;
		f=false;
		for(int j=1;j<=c[i];j++)
			s*=10;
		for(int j=0;j<n;j++)
			if(a[j]%s==b[i])
			{
				printf("%d\n",a[j]);
				f=true;
				break;
			}
		if(f==false)
			printf("%d\n",-1);
	}
	return 0;
}
