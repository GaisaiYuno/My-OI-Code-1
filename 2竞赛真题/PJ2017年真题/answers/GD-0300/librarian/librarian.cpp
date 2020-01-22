#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<deque>
using namespace std;
int n,m,s[1010],len,k;
bool _cmp(int a,int b)
{
	return a<b;
}
bool judge(int a,int b)
{
	int t=b,ju=0,ma=1;
	if (t==a) return true;
	for (;t!=0;)
	 {
	 	int yu=0;
	 	yu=t%10;
	 	yu*=ma;
	 	ma*=10;
	 	ju+=yu;
	 	t/=10;
	 	if (ju==a) return true;
	 }
	return false;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%D",&n,&m);
	for (int i=1;i<=n;i++)
	 scanf("%d",&s[i]);
	sort(s+1,s+n+1,_cmp);
	for (int i=1;i<=m;i++)
	 {
	 	scanf("%d",&len);
	 	scanf("%d",&k);
	 	bool jud=false;
	 	for (int j=1;j<=n;j++)
	 	 if (judge(k,s[j])) {printf("%d\n",s[j]); jud=true;break; };
	 	if (!jud) printf("-1\n");
	 } 
	return 0;
}

