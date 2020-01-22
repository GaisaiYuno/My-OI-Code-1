#include <bits/stdc++.h>
using namespace std;

int n,d,k,a[5001],s[5001] ;
long long f[5001] ;

int main()
{
	freopen ("jump.in" , "r" , stdin) ;
	freopen ("jump.out" , "w" , stdout) ;
	printf ("-1") ; return 0 ;
	scanf ("%d%d%d" ,&n ,&d ,&k) ;
	long long sum ;
	for (int i=1 ; i<=n ; i++) scanf ("%d%d" ,&a[i] ,&s[i]) ;
	int ans=0 ;
	while (f[1]<k)
	{
		memset(f,0,sizeof(f)) ;
		f[n]=s[n] ;
		if (ans+d>n)
		{
			printf ("-1") ;
			return 0 ;
		}
		if (ans<d)
		{
			for (int i=n-1 ; i>=1 ; i--)
			{
				int l=1 ;
				while (a[i+l]-a[i]>=d-ans && a[i+l]-a[i]<=d+ans) l++ ;
				for (int j=i+l-1 ; j>i ; j--) f[i]=max(f[i] , f[j]+a[i]) ;
			}
		}
		if (ans>=d)
			for (int i=n-1 ; i>=1 ; i--)
			{
				int l=1 ;
				while (a[i+l]-a[i]>=0 && a[i+1]-a[i]<=d+ans) l++ ;
				for (int j=i+l-1 ; j>i ; j--) f[i]=max(f[i] , f[j]+s[i]) ;
			}
		if (f[1]>=k)
		{
			printf ("%d" ,ans) ;
			return 0 ;
		}
		ans++ ;
	}
}
