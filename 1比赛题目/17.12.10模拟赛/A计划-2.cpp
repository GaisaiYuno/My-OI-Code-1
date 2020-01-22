//HDU 2102
#include<iostream>
#include<cstring>
#include<cmath>
#define maxn 11
using namespace std;
int c,n,m,maxt;
int xs,ys;
int xa,ya;
char a[maxn][maxn][2];
bool used[maxn][maxn][2];
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
int flag=0;
struct node{
	int x;
	int y;
	int floor;
	int t;
}queue[maxn*maxn];
/*void dfs(int x,int y,int floor,int t){
	int xx,yy;
	if(t>maxt) return;	
	//printf("t=%d (%d,%d,%d) '%c'\n",t,x,y,floor,a[x][y][floor]);
	if(x==xa&&y==ya&&floor==1){
		if(t<=maxt) flag=1;
		return;
	}
	if(a[x][y][floor]=='#'&&floor==0&&a[x][y][1]!='*') dfs(x,y,1,t);
	if(a[x][y][floor]=='#'&&floor==1&&a[x][y][0]!='*') dfs(x,y,0,t);
	if(a[x][y][0]=='#'&&a[x][y][1]=='#') return;
	for(int i=0;i<4;i++){
		xx=x+walkx[i];
		yy=y+walky[i];
		if(xx<0||yy<0||xx>=n||yy>=m||used[xx][yy][floor]||a[xx][yy][floor]=='*'){
	       xx=x;
		   yy=y; 
		   continue;
		} 
		used[xx][yy][floor]=true;
		dfs(xx,yy,floor,t+1);
		used[xx][yy][floor]=false;
	}
}*/
int bfs(){
        int head=0;
		int tail=0;
		int x,y,floor;
		queue[0].x=xs;
		queue[0].y=ys;
		queue[0].floor=0;
		queue[0].t=0;
		do{
		    for(int i=0;i<4;i++){	
		        x=queue[head].x+walkx[i];
		        y=queue[head].y+walky[i];
		        floor=queue[head].floor;
				if(x>=0&&y>=0&&x<n&&y<m&&!used[x][y][floor]&&a[x][y][floor]!='*'){
					tail++;//½ø¶Ó
					queue[tail].x=x;
					queue[tail].y=y;
					if(a[x][y][floor]=='#'){
						queue[tail].floor=1-floor;
						queue[tail].t=queue[head].t+1;
					}
					else{
					   queue[tail].floor=floor; 
					   queue[tail].t=queue[head].t+1;
				    }
					used[x][y][floor]=true;
					//printf("t=%d (%d,%d,%d) '%c'\n",queue[tail].t,queue[tail].x,queue[tail].y,queue[tail].floor,a[x][y][floor]);
					if(a[x][y][floor]=='P') {
					    if(queue[tail].t<=maxt)return 1;
				    }	
				}	
		    }
		    head++;
		}while(head<=tail);	
	return 0;
}
int main(){
	cin>>c;
	while(c--){
		cin>>n>>m>>maxt;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j][0];
				if(a[i][j][0]=='S'){
					xs=i;
					ys=j;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j][1];
				if(a[i][j][1]=='S'){
					xs=i;
					ys=j;
				}
				if(a[i][j][1]=='P') {
				   xa=i;
				   ya=j;
			    }
			}
		}
		memset(used,false,sizeof(used));
		used[0][0][0]=true;
		if(bfs()==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
