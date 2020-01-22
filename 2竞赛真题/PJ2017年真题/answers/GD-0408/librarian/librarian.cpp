#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
int n,q,f,t;
int bok[1005],rade;
bool check(int a,int b)
{
	if(b>a) return false;
	while(b!=0)
	{
		if(a%10!=b%10) return false;
		else {a/=10; b/=10;}
	}
	return true;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&bok[i]);
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&t,&rade);
		f=-1;
		for(int j=0;j<n;j++)
		{
			if(check(bok[j],rade))
			{
				if(f!=-1) f=min(f,bok[j]);
				else f=bok[j];
			}
		}
		printf("%d\n",f);
	}
	return 0;
}
