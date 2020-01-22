//ball 
#include<iostream>
#include<cstdio>
#define maxn 35
#define maxm 35
using namespace std;
long long int n,m,ans=0;
int used[maxn][maxm];
void dfs(int pos,int step){
	//printf("%d %d\n",pos,step);
	if(pos==0&&step==m){
		ans++;
		return;
	}
	if(step==m) return;
	if(pos<n&&pos>=0&&used[pos][step]==0){
	   used[pos][step]=1; 
	   dfs((pos+1)%n,step+1);
	   dfs((pos+n-1)%n,step+1);
	} 
	used[pos][step]=0;
	return;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	dfs(0,0);
	cout<<ans;
	return 0;
}
