#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1010],b[1010];
int main()
{
	int n,q,c;
	bool is_;
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int j=1;j<=q;++j)
	{
		is_=false;
		scanf("%d",&c);
		scanf("%d",&b[j]);
		for(int i=1;i<=n;++i)
		{
			if(a[i]%(int)pow(10,c)==b[j])
			{
				printf("%d\n",a[i]);
				is_=true;
				break;
			}
		}
		if(is_==false) printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
