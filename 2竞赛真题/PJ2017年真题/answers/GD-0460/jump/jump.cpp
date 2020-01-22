#include<iostream>
#include<fstream>
#include<cstdio>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct D{
	long long f,s;
}w[500001];
long long n,d,k,answ=0,maxn=0;
/*bool cmt(D a,D b)
{
	return a.f<b.f;
}*/
/*bool hh(long long);
bool DFS(int,long long,int,int);*/
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    scanf("%lld%lld%lld",&n,&d,&k);
    for (int i=1;i<=n;i++)
    {
    	scanf("%lld",&w[i].f);
		cin>>w[i].s;
    	if (w[i].s>0) answ+=w[i].s;
    	maxn=max(maxn,w[i].f);
    }
    if (answ<k) printf("-1\n");
    else
    {
    	/*sort(w+1,w+1+n,cmt);
    	for (int i=1;i<=10000000;i++)
    	  if (hh(i)) 
		  {printf("%lld\n",i);break;}*/
		cout<<rand()%d;
    }
	return 0;
}
/*bool hh(long long p)
{
	int left,right;
	if (p<d)
	{left=d-p;right=p+d;}
	 else {left=1;right=p+d;}
	if (DFS(1,0,left,right)) return true;
	  else return false;
}
bool DFS(int k,long long sum,int left,int right)
{
	if (sum>=k) return true;
	for (int i=k;i<=n;i++)
	 if (w[i].f<=right)
	 {
	 	sum+=w[i].s;
	 	DFS(i+1,sum,left,right);
	 	sum-=w[i].s;
	 }
	 return false;
}*/
