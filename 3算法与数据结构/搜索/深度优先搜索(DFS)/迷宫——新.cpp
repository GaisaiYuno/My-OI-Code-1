//Âå¹È ×ßÃÔ¹¬ 
#include<iostream>
#include<cstring>
#define maxn 16
using namespace std;
int m,n,xs,ys,xe,ye;
int map[maxn][maxn];
int used[maxn][maxn];
bool flag=true;
string num[15]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14"};
void dfs(int x,int y,string s){
	
	if (used[x][y]==1||x<=0||y<=0||x>m||y>n){
		return;
	}
	//cout<<x<<' '<<y<<endl;
	if(x==xe&&y==ye){ 
		flag=false;
		s=s+"("+num[x]+","+num[y]+")\n";
		cout<<s;
	    return;
	}
	if(map[x][y]==1){ 
	used[x][y]=1; 
	s=s+"("+num[x]+","+num[y]+")"+"->";
	dfs(x-1,y,s);
	dfs(x,y-1,s);
	dfs(x,y+1,s);
	dfs(x+1,y,s);
	used[x][y]=0;
    } 
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) cin>>map[i][j];
	}
	cin>>xs>>ys>>xe>>ye;
	memset(used,0,sizeof(used));
	dfs(xs,ys,"");
	if(flag) cout<<-1;
	return 0;
} 
