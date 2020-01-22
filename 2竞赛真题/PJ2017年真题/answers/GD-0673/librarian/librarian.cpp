#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10000];
int main()
{
	freopen("librarian.in","r",stdin);freopen("librarian.out","w",stdout);
	
	int n,m,i,j;
	bool b;
	
	scanf("%d%d",&n,&m);
	
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	
	sort(a+1,a+1+n);
	
	for(i=1;i<=m;i++)
	{
		int t,x,kk=1;
		
		scanf("%d%d",&t,&x);
		
		for(int k=1;k<=t;k++)	kk*=10;
		
		for(j=1;j<=n;j++)
		{
			int s=a[j]%kk;
			b=false;
			
			if(s==x) 
			{
				cout<<a[j]<<endl;
				b=true;
				break;
			}
			
		}
		
		if(!b) cout<<-1<<endl;
		
	}
	return 0;
}
