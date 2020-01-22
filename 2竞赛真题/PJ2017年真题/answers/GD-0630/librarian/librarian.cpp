#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;int a[1000];
void check(int c,int com)
{
	int mine=50000000,w=0;
	for (int i=0;i<n;i++)
	{
		int t=1;
		for (int i=1;i<=c;i++) t*=10;
		if ((a[i]%t==com)&&(mine>a[i]/t,mine))
		{mine=min(a[i]/t,mine);w=i;}
	}
	if (mine!=50000000) printf("%d\n",a[w]);else cout<<-1<<endl;
	return;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for (int i=0;i<n;i++) scanf("%d\n",&a[i]);
    for (int i=0;i<m;i++)
    {
    	int e,q;
    	scanf("%d %d\n",&e,&q);
    	check(e,q);
    }
    return 0;
}
