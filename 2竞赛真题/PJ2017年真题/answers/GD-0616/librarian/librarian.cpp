#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
using namespace std;
int n,q,a,b;
int m[1001];
int i,j,l,cmp;
int test(int c,int a,int b)
{
	int k,j=1;
	k=m[c]-b;
	for(l=0;l<a;l++) j=j*10;
	if(k%j==0||k==0&&c<=n) printf("%d",m[c]);
	else if(c<n) test(c+1,a,b);
	else printf("-1");
	
}
int main()
{
freopen("librarian.in","r",stdin);
freopen("librarian.out","w",stdout);
scanf("%d%d",&n,&q);
for(i=1;i<=n;i++)scanf("%d",&m[i]);
for(i=1;i<=n;i++)
{for(j=i+1;j<=n;j++)
	if(m[i]>m[j])
	{cmp=m[i];
	m[i]=m[j];
	m[j]=cmp;	
	}
}
for(i=1;i<=q;i++)
{	scanf("%d%d",&a,&b);
	test(1,a,b);
}
fclose(stdin);
fclose(stdout);
return 0;
}
