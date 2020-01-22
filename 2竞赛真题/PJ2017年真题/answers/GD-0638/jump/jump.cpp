#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int n,d,k;
int x[500050],y[500050];
bool flag;
int sum=0;
int l,r,mid;
void dfs(int dep,int l,int r)
{
	int sums;
	if (dep>n) {
	  if (sums>=k) flag=true;
	  return; 
	}
	  sums+=y[dep]; 
	  dfs(dep+1,l,r);
	  sums-=y[dep];
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++) {
	  scanf("%d%d",&x[i],&y[i]);
	  if (y[i]>0) sum=sum+y[i];
	}
	if (sum<k) {
		printf("%d",-1);
		return 0;
	}
	if (d==1) {
	  printf("%d",0);
	  return 0;
	}
	l=1; r=n;
	while (l<=r) {
	  mid=(l+r)>>1;
	  flag=false;
	  if (mid>=d) dfs(1,1,mid+d);
	  else dfs(1,mid-d,mid+d);
	  if (flag) r=mid-1;
	  else l=mid+1;
	}
	printf("%d",l+1);
	fclose(stdin); fclose(stdout);
	return 0;
}
