#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std ;

const int N = 20 ;
int n , d , k , x[N] , s[N] , f[N] , ans[N];
 
int find(int w){//Ñ°ÕÒ x[I]>W,µÄmin(I) 
	int L = 1 , R = n , M;
	if ( x[L]>w ) return L ;
	while ( L+1<R ){
		M = (L+R) / 2 ;
		if ( x[M]>w ) R = M ;
				 else L = M ;
	}
	return R ;
}
int isok(int g){//O(n^2)
	
	for (int i = 1; i <= n; i ++) ans[i] = 0 ;
/*	for (int i = 1; i <= n; i ++){
		for (int j = max(1,x[i]-d-G); j < min(i,x[i]-d+G); j ++){
			ans[i] = max(ans[i],s[j]+s[i]) ;
		}
		if ( ans[i] >= k ) return 1 ;
	}*/
	f[0] = 1 ;
	for (int i = 0; i <= n; i ++){
		if ( f[i] ) 
		for (int j = max(1,find(d-g-1)); j <= min(find(d+g)-1,x[n]-x[i]); j ++){
			f[i+j] = 1 ;
			ans[i+j] = max(ans[i+j],ans[i]+s[i+j]) ;
			if ( ans[i+j] >= k ) return 1 ;
		}
	}
	return 0 ;
}

int work1(){//O(50*n^2)
	
	int L = 0 , R = x[n] , M ;
	while ( L+1 < R ) {
		M = (L+R) / 2 ;
		if ( isok(M) ) R = M ;
				  else L = M ;
	}
	if ( isok(L) ) return L ;
	if ( isok(R) ) return R ;
	return -1 ;
}

int main()

{
	freopen("jump.in","r",stdin) ;
	freopen("jump.out","w",stdout) ;

	cin >> n >> d >> k ;
	int MaxTot = 0 ;
	for (int i = 1; i <= n; i ++) {
		cin >> x[i] >> s[i] ;
		if ( s[i]>0 ) MaxTot+=s[i] ;
	}
	
	if ( MaxTot < k ) {
		cout << -1 ; 
		return 0 ;
	}
	if ( n <= 1000 ) {
		cout << work1() ;
		return 0 ;
	}
	

	return 0 ;
}
