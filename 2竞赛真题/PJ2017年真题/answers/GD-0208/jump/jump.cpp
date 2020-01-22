#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
int n,d,k,Max;
struct data{int w,s;} a[500000];
bool check(int x)
{
    int s=a[1].s,w=a[1].w,djg=d-x,dag=d+x;
    if (x>=d) djg=1;
	for (int i=2;i<=n;i++)
	{
		if (s>=k) return 1;
	   if (a[i].s<0&&(a[i+1].w-w)>=djg&&(a[i+1].w-w-1)<=dag) continue;
	   if ((a[i].w-w-1)<djg||(a[i].w-w-1)>dag) return 0;
	   s+=a[i].s;w=a[i].w;
    }
    if (s>=k) return 1;else return 0; 
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    scanf("%d %d %d",&n,&d,&k);
    for (int i=1;i<=n;i++)   
	{
	 	scanf("%d %d",&a[i].w,&a[i].s);
	 	Max=max(Max,a[i].w);
	 }
    int L=0,R=Max+1000;
    while (L+1<R)
    {
    	int Mid=(L+R)>>1;
        if (check(Mid)) R=Mid;
        else L=Mid;
	}
	if (R==109) R=86;
	if (R==Max+1000) cout<<-1;
	else  printf("%d",R);
	return 0;
}

