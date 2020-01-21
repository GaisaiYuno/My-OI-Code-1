
//递推类型3 
#include<iostream>
#define maxn 1005 
using namespace std;
int map[maxn][maxn];
int f[maxn][maxn][5];
int n,m,ans=0; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>map[i][j];
	}

	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++)
			f[a][b][1]=max(f[a][b-1][1],f[a-1][b][1])+map[a][b];
	}
	for(int a=n;a<=1;a--){
		for(int b=n;1<=m;b++)
			f[a][b][3]=max(f[a][b+1][3],f[a-1][b][3])+map[a][b];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int a=i;a<=n;a++){
				for(int b=j;b<=m;b++)
				    f[a][b][2]=max(f[a][b-1][2],f[a-1][b][2])+map[a][b];
			}
			for(int a=i;a<=1;a--){
				for(int b=j;b<=m;b++)
				    f[a][b][4]=max(f[a][b+1][4],f[a-1][b][4]+map[a][b]);
			}
			ans=max(ans,f[i][j][1]+f[i][j][2]+f[i][j][3]+f[i][j][4]);
		} 
	}
	cout<<ans;
	return 0; 
} 
/*递推公式 
相遇点（i,j) 
A -> (i,j)
f[a,b]=max(f[a,b-1],f[a-1,b])

B ->(i,j) 
f[a,b]=max(f[a,b+1],f[a-1,b])

(i,j) -> (n,m)
f[a,b]=max(f[a,b-1],f[a-1,b])

(i,j) -> (1,m)
f[a,b]=max(f[a,b+1],f[a-1,b])
*/

