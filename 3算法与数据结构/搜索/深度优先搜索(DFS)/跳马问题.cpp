//Âå¹È ÌøÂíÎÊÌâ 
#include<iostream>
#include<cstring>
#define max 20
using namespace std;
int m,n;
int used[max][max]; 
int sum=0;
void dfs(int x,int y){
	if(x<0||x>m||y<0||y>n||used[x][y]==1) return;
	if(x==m&&y==n){
		sum++;
		return;
	}
	//cout<<x<<' '<<y<<endl; 
	used[x][y]=1;
	dfs(x+2,y+1);
	dfs(x+1,y+2);
	dfs(x+2,y-1);
	dfs(x+1,y-2);
	used[x][y]=0;
	
}
int main(){
	cin>>n>>m;
	memset(used,0,sizeof(used));
	dfs(0,0);
	cout<<sum;
} 
