#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

int totbook,totreader;
int readerwant,readersize;
int bookmark[1001];
bool flag;

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	int i,j,tmp;
	
	scanf("%d%d",&totbook,&totreader);
	for(i=1;i<=totbook;++i)
	{
		scanf("%d",&bookmark[i]);
	}
	sort(bookmark+1,bookmark+1+totbook);
	
	for(i=1;i<=totreader;++i)
	{
		scanf("%d%d",&readersize,&readerwant);
		tmp=1;flag=false;
		for(j=1;j<=readersize;++j) tmp*=10;
		for(j=1;j<=totbook;++j)
		{
			if(bookmark[j]%tmp==readerwant)
			{
				printf("%d\n",bookmark[j]);
				flag=true;
				break;
			}
		}
		if(flag==false) printf("-1\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
