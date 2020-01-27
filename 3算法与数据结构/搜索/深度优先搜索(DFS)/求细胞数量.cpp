//洛谷 求细胞数量 1451 
#include<iostream>
#include<cstring>
#define maxn 1000
using namespace std;
int m,n;
int a[maxn][maxn];
void dfs(int x,int y){
	if(x<0||y<0||x>=m||y>=n||a[x][y]==0) return ;
	else{
		a[x][y]=0;
		dfs(x+1,y);
		dfs(x-1,y);
		dfs(x,y+1);
		dfs(x,y-1);
	}
}
int main(){
	int ans=0;
	cin>>m>>n;
	memset(a,0,sizeof(a));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++) {
				scanf("%1d",&a[i][j]); //一定要用scanf，用cin只能输入一个数 
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]!=0){
				ans++;
				dfs(i,j);
			}
		}
	}
	cout<<ans;
} 
