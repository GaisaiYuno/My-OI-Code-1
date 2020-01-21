//洛谷 取数游戏 
#include<iostream>
#include<cstring>
#define max 16
using namespace std;
int T;
int n,m; 
int map[max][max];
int used[max][max];
int ans=0;
//int xx[8]={0,0,-1,1,-1,-1,1,1},yy[8]={-1,1,0,0,-1,1,-1,1};
int xx[4]={1,1,0,1},yy[4]={0,1,1,-1};
void dfs(int num,int h,int l){
	if(l>=m){//列超出
        h++;
        l=0;
    } 
    if(h>=n){//行超出
         if(num>ans)ans=num;
        return;
    }
    if(used[h][l]==0){
    	int u;
    	for(u=0;u<4;u++) used[h+xx[u]][l+yy[u]]++;
    	dfs(num+map[h][l],h,l+2);
    	for(u=0;u<4;u++) used[h+xx[u]][l+yy[u]]--;
	}
    dfs(num,h,l+1);
}
int main( ){
	cin>>T;
	for(int a=0;a<T;a++){
		cin>>n>>m;
		for(int b=0;b<n;b++){
			for(int c=0;c<m;c++) cin>>map[b][c];
		} 
		memset(used,0,sizeof(used));
		ans=0;
		dfs(0,0,0);
	 cout<<ans<<endl;
	}
} 
