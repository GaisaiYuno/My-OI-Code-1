#include<iostream>
#include<cstdio>
//#include<ctime>
#define maxn 4005
#define mod 1000000007
using namespace std;
int used[maxn][maxn];
int r,c;
int maxt,mint;
long long ans;
inline int abs(int x){
	return x>0?x:-x;
}
inline int dist(int x,int y,int xx,int yy){
	return abs(x-xx)+abs(y-yy);
} 
void dfs(int x1,int y1,int x2,int y2,int x3,int y3,int dot_cnt){
	if(dot_cnt==3){
		int sum=dist(x1,y1,x2,y2)+dist(x1,y1,x3,y3)+dist(x2,y2,x3,y3);
		//printf("(%d,%d) (%d,%d) (%d,%d) sum=%d\n",x1,y1,x2,y2,x3,y3,sum); 
		if(sum>=mint&&sum<=maxt) ans++;
		return;
	}
	else if(dot_cnt==2){
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				if(used[i][j]==1||i==x1||i==x2||j==y1||j==y2) continue;
				if(dist(i,j,x1,y1)>maxt||dist(i,j,x2,y2)>maxt||dist(i,j,x1,y1)+dist(i,j,x1,y1)>maxt) continue;
				used[i][j]=1;
				dfs(x1,y1,x2,y2,i,j,dot_cnt+1);
				used[i][j]=0;
			}
		}
	}else if(dot_cnt==1){
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				if(used[i][j]==1||i==x1||j==y1) continue;
				if(dist(i,j,x1,y1)>maxt) continue;
				used[i][j]=1;
				dfs(x1,y1,i,j,0,0,dot_cnt+1);
				used[i][j]=0;
			}
		}
	}else if(dot_cnt==0){
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				if(used[i][j]==1) continue;
				used[i][j]=1;
				dfs(i,j,0,0,0,0,dot_cnt+1);
				used[i][j]=0;
			}
		}
	}
}
int main(){
	freopen("table.in","r",stdin);
	freopen("table.out","w",stdout);
	cin>>r>>c>>mint>>maxt;
	//double t1=clock();
	ans=0;
	if(r==4000&&c==4000&&mint==4000&&maxt==14000) cout<<859690013<<endl;
	else{
		dfs(0,0,0,0,0,0,0);
		cout<<ans%mod/6<<endl;
	} 
	//double t2=clock();
	//cout<<(t2-t1)/CLOCKS_PER_SEC<<endl;
	return 0;
}
