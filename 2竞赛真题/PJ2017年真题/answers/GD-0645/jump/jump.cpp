#include<cstdio>
#include<iostream>
using namespace std;
const int INF=1e9;
int s[2005],ans[2005],x[2005];
int n,d,k,m=0,l,r;
bool test(int g)
{
	int maxn=0;
	if(x[0]>=d-g&&x[0]<=d+g) ans[0]=s[0];
	else ans[0]=0-INF;
	for(int i=1;i<n;i++)
	{
		ans[i]=0-INF;
		for(int j=0;j<i;j++)
		{
			if(x[i]-x[j]>=d-g&&x[i]-x[j]<=d+g&&ans[j]+s[i]>ans[i]) ans[i]=ans[j]+s[i];
		}
		if(ans[i]>maxn) maxn=ans[i];
	}
	return maxn>=k;
}
int main()
{
	freopen("jump.in","r",stdin);	
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&s[i]);
		if(s[i]>0) m+=s[i]; 
	}
	if(m<k) printf("-1");
	else
	{
		l=0;r=x[n-1]-d+1;
		while(l+1<r)
		{
			m=(l+r-1)/2;
			if(test(m)) r=m+1;
			else l=m+1;
		}
	}
	printf("%d",l);
	fclose(stdin);fclose(stdout);
	return 0;
}
