#include<cstdio>
#include<cstring>
using namespace std;
const int Ind=1000000000;
int xl[4][2]={{1,0},{-1,0},{0,1},{0,-1}},minn=Ind,count=0;
int n,m,x1,y1,c,a[105][105],sum=0,f=0,book[105][105]={0};
void dfs(int x,int y,int k){
	if(x==m&&y==m)
		if(sum<minn){minn=sum;return ;}
	if(a[x+xl[0][0]][y+xl[0][1]]==-1&&a[x+xl[1][0]][y+xl[1][1]]==-1&&a[x+xl[2][0]][y+xl[2][1]]==-1&&a[x+xl[3][0]][y+xl[3][1]]==-1)return ;
	for(int i=0;i<4;i++)
		if(!book[x+xl[i][0]][y+xl[i][1]]&&x+xl[i][0]<=m&&x+xl[i][0]>=1&&y+xl[i][1]<=m&&y+xl[i][1]>=1){
		if(a[x+xl[i][0]][y+xl[i][1]]==-1){
			if(f)continue;
			sum+=2;f=1;
			book[x+xl[i][0]][y+xl[i][1]]=1;
			dfs(x+xl[i][0],y+xl[i][1],a[x][y]);
			book[x+xl[i][0]][y+xl[i][1]]=0;
			sum-=2;f=0;
		}
		if(a[x+xl[i][0]][y+xl[i][1]]==a[x][y]||a[x+xl[i][0]][y+xl[i][1]]==k){
			book[x+xl[i][0]][y+xl[i][1]]=1;f=0;
			dfs(x+xl[i][0],y+xl[i][1],-2);
			book[x+xl[i][0]][y+xl[i][1]]=0;
		}
		if(a[x+xl[i][0]][y+xl[i][1]]!=-1){
			sum++;f=0;
			book[x+xl[i][0]][y+xl[i][1]]=1;
			dfs(x+xl[i][0],y+xl[i][1],-2);
			book[x+xl[i][0]][y+xl[i][1]]=0;
			sum--;
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	memset(a,-1,sizeof(a));
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x1,&y1,&c);
		a[x1][y1]=c;
	}
	book[1][1]=1;
	dfs(1,1,-2);
	if(minn!=Ind)printf("%d",minn);
	else printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
