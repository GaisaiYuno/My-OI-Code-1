#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define sr c=getchar()
#define input read()
#define pd (c<'0'||c>'9')
using namespace std;
int n,m;
int book[1011];	int z[1011];
int numb[111];
int len;
bool ok;
bool cmp(int x,int y)
{
	return x<y;
}
bool pds(int x)
{

	int j=0;
	while (x>0)
	{
		j++;
		z[j]=x%10;
		x/=10;
		//printf("%d",z[j]);
	}
	int i=0;
	if (len>j) return false;
	for (int k=len;k>0;k--)
	{
		i++;
		if (z[i]!=numb[k]) return false;
	}
	return true;
}
int read()
{
	char c;int d=1,f=0;
	while (sr,pd) if (c=='-') d=-1;f=f*10+c-48;
	while (sr,!pd) f=f*10+c-48;
	return d*f;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	n=input;m=input;
	for (int i=1;i<=n;i++)
	 book[i]=input;
	sort(book+1,book+1+n,cmp);
	for (int i=1;i<=m;i++)
	{
	 len=input;char lc;//memset(numb,0,sizeof(numb));
	 for (int j=1;j<=len;j++) 
	 {
	 	lc=getchar();
	 	numb[j]=lc-48;
	 }ok=false;
	 for (int j=1;j<=n;j++)
	 {
	  if (pds(book[j])) {ok=true;printf("%d\n",book[j]);break;}
     }
	 if (!ok) printf("-1\n");
    }
    return 0;
}
