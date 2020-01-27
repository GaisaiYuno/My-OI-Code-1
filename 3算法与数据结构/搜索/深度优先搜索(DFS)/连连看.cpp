//HDU 1175
#include<iostream>
#include<cstring>
#define maxn 1005
using namespace std;
int n,m,q;
int chess[maxn][maxn];
int used[maxn][maxn];
int x1,y1,x2,y2; 
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
inline int fread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar(); 
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
bool dfs(int x,int y,int ex,int ey,int turn_cnt,int last_turn){
	//printf("(%d,%d)->(%d,%d),%d,%d\n",x,y,ex,ey,turn_cnt,last_turn); 
	if(turn_cnt>2) return false;
	if(x==ex&&y==ey) return true;
	int tx,ty;
	for(int i=0;i<4;i++){
		tx=x+walkx[i];
		ty=y+walky[i];
		if(tx>0&&ty>0&&tx<=n&&ty<=m&&used[tx][ty]==0&&(chess[tx][ty]==0||tx==ex&&ty==ey)){
			if(i!=last_turn&&last_turn!=-1){
				used[tx][ty]=1;
				if(dfs(tx,ty,ex,ey,turn_cnt+1,i)) return true;
				used[tx][ty]=0;
			}
			else{
				used[tx][ty]=1;
				if(dfs(tx,ty,ex,ey,turn_cnt,i)) return true;
				used[tx][ty]=0;
			}
		}
	}
	return false;
}
int main(){
	while(cin>>n>>m&&n!=0&&m!=0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				chess[i][j]=fread(); 
			}
		}
		cin>>q;
		while(q--){
			memset(used,0,sizeof(used));
			x1=fread();
			x2=fread();
			y1=fread();
			y2=fread();
			if(chess[x1][x2]!=chess[y1][y2])cout<<"NO"<<endl;
			else if(chess[x1][x2]==0||chess[y1][y2]==0) cout<<"NO"<<endl;
			else if(dfs(x1,x2,y1,y2,0,-1)) cout<<"YES"<<endl;
			else  cout<<"NO"<<endl;
		}
	}
	return 0;
}
