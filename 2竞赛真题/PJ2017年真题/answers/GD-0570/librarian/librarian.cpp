#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int n,q,i,j;
int a[1001],b,c;
int compare(int e,int f)
{
	int tem=10000001,sum,bb;
	bb=pow(10,e);
	for(j=0;j<n;j++)
	{
		if(a[j]*10>=bb)
		if(a[j]!=-1){
			
			sum=(a[j]%bb);
		if(sum==f&&a[j]<tem){
			tem=a[j];
	        }
		}
	}
	for(j=0;j<n;j++)if(a[j]==tem){a[j]=-1;break;
	}
	if(tem==10000001)return -1;
	return tem;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<q;i++)
	{
		scanf("%d%d",&b,&c);
		printf("%d\n",compare(b,c));
	}
	return 0;
}
