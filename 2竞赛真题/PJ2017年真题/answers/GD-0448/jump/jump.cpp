#include<cstdio>
using namespace std;
int n,d,k,l,s,t=0;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	for (int i=0;i<n;i++)
	{
		scanf("%d %d",&l,&s);
		t+=s;		
	}
	if (t<k) printf("-1");
	else printf("%d",l-d);
	fclose(stdin); fclose(stdout);
	return 0;	
}
