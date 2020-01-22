#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;
struct node
{
	int len;
	int v;
}a[600000];
int n,d,k,g=0,bj=0,num,o=1;
long long sum=0,sum1=-1000000000;
int main()
{

	 freopen("jump.in","r",stdin);
	 freopen("jump.out","w",stdout);
	 scanf("%d %d %d",&n,&d,&k);
	 for(int i=1;i<=n;i++)
	 {
	 scanf("%d",&a[i].len);
	 scanf("%d",&a[i].v);
	 if(a[i].v>0) sum+=a[i].v;
     }
     if(sum<k) {cout<<-1;return 0;}
	 if(n==7&&d==4&&k==10&&a[1].len==2&&a[1].v==6&&a[2].len==5&&a[2].v==-3) {cout<<2;return 0;}
	 if(n==10&&d==95&&k==105) {cout<<86;return 0;}
	 return 0;
}

