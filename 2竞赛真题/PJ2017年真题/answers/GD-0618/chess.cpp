#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
long sum,mon,m,n,x,y,a[1001][1001],fx[4][2];
bool p[1001][1001];
long dfs(long x,long y,long q,long mon){
	if(x<=0||x>m||y<=0||y>m)return 0;
	//cout<<x<<' '<<y<<' '<<q<<' '<<mon<<endl;
	if(x==m&&y==m){
		sum=min(sum,mon);return 0;
	}
	for(int i=0;i<4;i++){
		if(a[x+fx[i][0]][y+fx[i][1]]==a[x][y]&&p[x+fx[i][0]][y+fx[i][1]]==0){
			p[x+fx[i][0]][y+fx[i][1]]=1;//cout<<x<<' '<<y<<' '<<a[x][y]<<' '<<a[x+fx[i][0]][y+fx[i][1]]<<endl;
			dfs(x+fx[i][0],y+fx[i][1],0,mon);
			p[x+fx[i][0]][y+fx[i][1]]=0;
		}else if(p[x+fx[i][0]][y+fx[i][1]]==0){
			if(q==0&&a[x+fx[i][0]][y+fx[i][1]]==0){
				p[x+fx[i][0]][y+fx[i][1]]=1;a[x+fx[i][0]][y+fx[i][1]]=a[x][y];
				dfs(x+fx[i][0],y+fx[i][1],1,mon+2);
				p[x+fx[i][0]][y+fx[i][1]]=0;a[x+fx[i][0]][y+fx[i][1]]=0;
			}else if(a[x+fx[i][0]][y+fx[i][1]]!=0){
				p[x+fx[i][0]][y+fx[i][1]]=1;
				dfs(x+fx[i][0],y+fx[i][1],0,mon+1);
				p[x+fx[i][0]][y+fx[i][1]]=0;
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	sum=200000000;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		cin>>a[x][y];
		a[x][y]++;
	}
	fx[1][0]=1;fx[1][1]=0;
	fx[2][0]=-1;fx[2][1]=0;
	fx[3][0]=0;fx[3][1]=1;	
	fx[4][0]=0;fx[4][1]=-1;
	memset(p,0,sizeof(p));
	dfs(1,1,0,0);
	
	if(sum==200000000)cout<<-1;
	else cout<<sum;
	fclose(stdin);fclose(stdout);
}
