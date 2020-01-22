#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n,d,k,a[500005],t1,t2,m;
int oo=2147483647;
int check(int p)
{
	int res=0,tmax=0,t=0,l=0,lb=0,ub=0,len=0;
	if (p<d) lb=d-p,ub=d+p;
	if (p>=d) lb=1,ub=d+p;
	while (l<m){
		t=-oo;
		len=l;
		for (int i=len+lb;i<=len+ub;i++)
			if (a[i]>t){
				t=a[i];l=i;
				if (t>=0) break;
			}
		if (t==-oo) return 0;
		tmax+=t;res=max(res,tmax);
	}
	if (res>=k) return 1;
	else return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (int i=1;i<500005;i++)
		a[i]=-oo;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&t1,&t2);
		a[t1]=t2;m=max(m,t1);
	}
	int L=0,R=1000000005,mid;
	while (L+1<R)
	{
		mid=(L+R)/2;
		if (check(mid)) R=mid;
		else L=mid;
	}
	if (R==1000000005) R=-1;
	cout<<R;
	return 0;
}
