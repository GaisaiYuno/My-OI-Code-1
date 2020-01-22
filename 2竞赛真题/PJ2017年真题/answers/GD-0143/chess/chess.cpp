#include<iostream>
#include<cstdio>
using namespace std;
int cb[110][110];
int check[110][110];
int n,m,x,ans=9999999;
int dfs(int x,int y,int v,int z,int cl){
if(x==m&&y==m){
	ans=min(ans,v);return 0;
}
if(check[x][y]<=v)return 0;
check[x][y]=min(check[x][y],v);
if(x+1<=m){
int bx=x+1;int by=y;
if(cb[bx][by]==cl)dfs(bx,by,v,0,cl);
if(cb[bx][by]!=cl&&cb[bx][by]!=0)dfs(bx,by,v+1,0,cb[bx][by]);
if(cb[bx][by]==0&&z!=1){
if(cl==1){dfs(bx,by,v+2,1,1);dfs(bx,by,v+3,1,2);
}
if(cl==2){dfs(bx,by,v+3,1,1);dfs(bx,by,v+2,1,2);	
}
}
}
if(y-1>0){
int bx=x;int by=y-1;
if(cb[bx][by]==cl)dfs(bx,by,v,0,cl);
if(cb[bx][by]!=cl&&cb[bx][by]!=0)dfs(bx,by,v+1,0,cb[bx][by]);
if(cb[bx][by]==0&&z!=1){
if(cl==1){dfs(bx,by,v+2,1,1);dfs(bx,by,v+3,1,2);
}
if(cl==2){dfs(bx,by,v+3,1,1);dfs(bx,by,v+2,1,2);	
}
}
}
if(y+1<=m){
int bx=x;int by=y+1;
if(cb[bx][by]==cl)dfs(bx,by,v,0,cl);
if(cb[bx][by]!=cl&&cb[bx][by]!=0)dfs(bx,by,v+1,0,cb[bx][by]);
if(cb[bx][by]==0&&z!=1){
if(cl==1){dfs(bx,by,v+2,1,1);dfs(bx,by,v+3,1,2);
}
if(cl==2){dfs(bx,by,v+3,1,1);dfs(bx,by,v+2,1,2);	
}
}
}
if(x-1>0){
int bx=x-1;int by=y;
if(cb[bx][by]==cl)dfs(bx,by,v,0,cl);
if(cb[bx][by]!=cl&&cb[bx][by]!=0)dfs(bx,by,v+1,0,cb[bx][by]);
if(cb[bx][by]==0&&z!=1){
if(cl==1){dfs(bx,by,v+2,1,1);dfs(bx,by,v+3,1,2);
}
if(cl==2){dfs(bx,by,v+3,1,1);dfs(bx,by,v+2,1,2);	
}
}	
}
}	
int main(){
freopen("chess.in","r",stdin);
freopen("chess.out","w",stdout);
for(int i=1;i<110;i++)for(int j=1;j<110;j++)check[i][j]=9999999;	
scanf("%d%d",&m,&n);
for(int i=1;i<=n;i++){
int ax,ay;
scanf("%d%d%d",&ax,&ay,&x);
cb[ax][ay]=x+1;	
}
dfs(1,1,0,0,cb[1][1]);
if(ans==9999999){
	printf("-1");
	return 0;
}
printf("%d",ans);
return 0;	
}
