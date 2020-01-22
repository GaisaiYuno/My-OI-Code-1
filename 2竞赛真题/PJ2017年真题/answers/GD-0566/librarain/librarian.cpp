#include<iostream>
#include<cstdio>
using namespace std;
int n,q,s[10005],r[10005],i,j,an[10005],w[10005];
bool ch(int a,int b)
{
	int t=1;
	if(s[a]<r[b])return 0;
	for(int k=1;k<=w[b];k++) t*=10;
	t=s[a]%t;
	if(t==r[b])return 1;
	return 0;
}
int pd()
{
	if(an[i]==-1)return s[j];
	if(an[i]>s[j])return s[j];
	return an[i];
}
int main()
{
	freopen("librarian2.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(i=0;i<=q+1;i++)an[i]=-1;
	for(i=1;i<=n;i++)
	    scanf("%d",&s[i]);
	for(i=1;i<=q;i++)
	    scanf("%d%d",&w[i],&r[i]);
	    
	    
	for(i=1;i<=q;i++)
	for(j=1;j<=n;j++)
	    if(ch(j,i))
	    	an[i]=pd();
	for(i=1;i<=q;i++)
	printf("%d\n",an[i]);
	return 0;
}
