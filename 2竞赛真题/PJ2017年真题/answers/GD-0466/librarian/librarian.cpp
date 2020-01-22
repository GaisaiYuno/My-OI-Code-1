#include <bits/stdc++.h>
using namespace std;

int n,q,l,m,a[1001] ;

int main()
{
	freopen ("librarian.in" , "r" , stdin) ;
	freopen ("librarian.out" , "w" , stdout) ;
	scanf ("%d%d" ,&n ,&q) ;
	for (int i=1 ; i<=n ; i++) scanf ("%d" ,&a[i]) ;
	for (int i=1 ; i<=q ; i++)
	{
		int ans=20000001 ;
		scanf ("%d%d" ,&l ,&m) ;
		int mod=pow(10 , l) ;
		for (int j=1 ; j<=n ; j++)
			if (a[j]%mod==m) ans=min(ans , a[j]) ;
		if (ans==20000001) printf ("-1\n") ;
		else printf ("%d\n" ,ans) ;
	}
	return 0 ;
}
