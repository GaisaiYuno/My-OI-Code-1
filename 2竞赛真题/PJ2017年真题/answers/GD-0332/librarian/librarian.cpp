#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std ;

const int N = 1000 + 10 ;
int b , p , len , peo , book[N] , BookLen[N] ;

int P(int k){
	int sum = 1 ;
	for (int i = 1; i <= k ; i ++ ) sum *= 10 ;
	return sum ;
}

int main()
{
	freopen("librarian.in","r",stdin) ;
	freopen("librarian.out","w",stdout) ;

	cin >> b >> p ;
	for (int i = 1; i <= b; i ++) cin >> book[i] ;
	
	for (int i = 1; i <= p; i ++){
		cin >> len >> peo ;
		int ans = 10000007 ;
		for (int j = 1 ; j <= b; j ++)
			if ( book[j]%P(len) == peo ) ans = min(ans,book[j]) ;
		if ( ans != 10000007 ) cout << ans << endl ;
						  else cout << -1 << endl ;
	}
	
	return 0 ;
}

