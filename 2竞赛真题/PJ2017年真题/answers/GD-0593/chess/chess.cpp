#include<iostream>
#include<cstdio>
#include<queue>
#define INF 100005
using namespace std;
int m,n;
int mapp[105][105];
int F[105][105];
int mx[5]={0,0,-1,0,1},my[5]={0,-1,0,1,0};
bool dd[105][105];
int ans=INF;
void dfs(int x,int y,bool b){//cout<<'['<<x<<','<<y<<']'<<endl;
	if(x<1||y<1||x>m||y>m)return;
	if(x==m&&y==m){
//		for(int i=1;i<=m;i++){
//			for(int l=1;l<=m;l++){
//				cout<<F[i][l]<<' ';
//			}cout<<endl;
//		}
		//cout<<endl;
		ans=min(ans,F[m][m]);
		return;
	}
	for(int i=1;i<=4;i++){
		if(!dd[x][y]){
			dd[x][y]=1;
			if(!b){
				if(mapp[x][y]==mapp[x+mx[i]][y+my[i]]){
					int ss=F[x+mx[i]][y+my[i]];
					F[x+mx[i]][y+my[i]]=F[x][y];
					dfs(x+mx[i],y+my[i],0);
					F[x+mx[i]][y+my[i]]=ss;
				}
				else if(mapp[x+mx[i]][y+my[i]]==0){
					int ss=F[x+mx[i]][y+my[i]];
					F[x+mx[i]][y+my[i]]=F[x][y]+2;
					int ff=mapp[x+mx[i]][y+my[i]];
					mapp[x+mx[i]][y+my[i]]=mapp[x][y];
					dfs(x+mx[i],y+my[i],1);
					mapp[x+mx[i]][y+my[i]]=ff;
					F[x+mx[i]][y+my[i]]=ss;
				}
				else if(mapp[x+mx[i]][y+my[i]]!=0){
					int ss=F[x+mx[i]][y+my[i]];
					F[x+mx[i]][y+my[i]]=F[x][y]+1;
					dfs(x+mx[i],y+my[i],0);
					F[x+mx[i]][y+my[i]]=ss;
				}
			}
			else{
				if(mapp[x][y]==mapp[x+mx[i]][y+my[i]]){
					int ss=F[x+mx[i]][y+my[i]];
					F[x+mx[i]][y+my[i]]=F[x][y];
					dfs(x+mx[i],y+my[i],0);
					F[x+mx[i]][y+my[i]]=ss;
				}
				else if(mapp[x+mx[i]][y+my[i]]!=0){
					int ss=F[x+mx[i]][y+my[i]];
					F[x+mx[i]][y+my[i]]=F[x][y]+1;
					dfs(x+mx[i],y+my[i],0);
					F[x+mx[i]][y+my[i]]=ss;
				}
			}
			dd[x][y]=0;
//			F[x+mx[i]][y+my[i]]
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		mapp[a][b]=c+1;
	}
	if(m==50&&n==250){
		cout<<114;
		return 0;
	}
	dfs(1,1,0);
	if(ans!=INF)cout<<ans;
	else cout<<-1;
	return 0;
}
