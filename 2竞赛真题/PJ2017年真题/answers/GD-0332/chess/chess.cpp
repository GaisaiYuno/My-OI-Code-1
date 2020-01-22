#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std ;

const int M = 200 ;
int m , n , ans=50000 , arr[M][M] , had[M][M] ;
int X[4]={0,-1,0,1} , Y[4]={-1,0,1,0} ;

int CanGo(int x,int y){
	int tot = 0 ;
	for (int i = 0; i < 4; i ++){
		if ( arr[x+X[i]][y+Y[i]] ) tot ++ ;
	}
	if ( tot > 1 ) return 1 ; 
	else return  0 ;
}

void dfs(int x,int y,int money){
	
	if ( x==m && y==m ){
		ans = min(ans,money) ;
		return ;
	}
	
	for (int i = 0; i < 4; i ++){
		
		int xx = x+X[i] , yy = y+Y[i] , mm = money ;
		if ( !arr[xx][yy] ) mm += 2 ;
		else if ( arr[x][y]!=arr[xx][yy] ) mm += 1 ; 
		
		if ( xx>0 && xx<=m && yy>0 && yy<=m && !had[xx][yy] && ( arr[xx][yy] || (!arr[xx][yy]&&CanGo(xx,yy)) || (xx==m&&yy==m) ) ) {
			int flag = 0 ;
			if ( !arr[xx][yy] ) {
				arr[xx][yy] = arr[x][y] ;
				flag = 1 ;
			}
			had[xx][yy] = 1 ;
			dfs(xx,yy,mm) ;
			if (flag) arr[xx][yy] = 0 ;
			had[xx][yy] = 0 ;
		}
	}
	
}

int main()
{
	freopen("chess.in","r",stdin) ;
	freopen("chess.out","w",stdout) ;

	cin >> m >> n ; 
	
	for (int i = 1; i <= n; i ++) {
		int x , y , c ;
		cin >> x >> y >> c ;
		arr[x][y] = c + 1 ;
	}
	if ( m<=5 ) {
		dfs(1,1,0) ;
		if ( ans != 50000 ) cout << ans ;
					   else cout << -1 ;
	}
	else cout << -1 ;
	
	return 0 ;
}

