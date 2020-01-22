#include<cstdio>
#include<iostream>
using namespace std;
int n,d,k,i,j,tem=0,g=0,sb;
int a[500001],b[500001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(b[i]>0)tem+=b[i];
	}
	if(tem<k){
		printf("-1");
		return 0;
	}
	tem=0;
	a[0]=0;
	for(i=1;i<=n;i++)
	{
	if(b[i]<0&&b[i+1]>b[i]&&(a[i+1]-a[i-1])<=(d+g)&&(a[i+1]-a[i-1])>=(d-g))
		{
			i++;
			tem=b[i]+tem;
			if(tem>=k){
				printf("%d",g);
				return 0;
			}
		}
		sb=a[i]-a[i-1];
		if(sb>d+g)g=sb-d;
		else if(sb<d-g)g=d-sb;
		tem=tem+b[i];
		if(tem>=k){
		printf("%d",g);
		return 0;
		}
	}
	return 0;
}
