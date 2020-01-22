#include<cstdio>
using namespace std;
int n,d,k,x[500001],s[500001],g=0,num=0,maxn=0;
void dfs(int a)
{
	int i;
	for(i=a+1;i<=n;i++)
	{
		if((x[i]-x[a]>=1 && x[i]-x[a]>=d-g) && (x[i]-x[a]<=d+g)) {num+=s[i]; dfs(i); num-=s[i];}
		if(i==n && num>maxn) maxn=num;	
	}
	return;
}
int main()
{
	int i,q=0;
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k); x[0]=s[0]=0;
	for(i=1;i<=n;i++){scanf("%d%d",&x[i],&s[i]);if(s[i]>0) q+=s[i];}
	if(k>q) printf("-1");
	else
		while(1)
		{
			dfs(0); 
			if(maxn>=k){printf("%d",g); break;} 
			else g++;
		}	
	fclose(stdin); fclose(stdout);
	return 0;
}
