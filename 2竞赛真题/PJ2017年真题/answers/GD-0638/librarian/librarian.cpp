#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int n,q;
int a[1050];
int l,num;
int ans=0;
bool find(int x,int y)
{
	int x2,k=1;
	x2=x; int c=0;
	while (x2>0) {
	  c=c+(x2%10)*k;
	  k=k*10;
	  x2=x2/10;
	  if (c==y) return true;
	  if (c>y) return false;
	}
	return false;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=q;i++) {
	  scanf("%d%d",&l,&num);
	  ans=-1;
	  for (int j=n;j>=1;j--) {
	  	if (a[j]<num) continue;
	    if (find(a[j],num)) ans=a[j];	
	}
	  if (i!=q) printf("%d\n",ans);
	  if (i==q) printf("%d",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}

