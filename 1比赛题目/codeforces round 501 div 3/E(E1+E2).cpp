#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 1005
using namespace std;
int n,m;
char a[maxn][maxn]; 
int vis[maxn][maxn];
struct node{
	int x;
	int y;
	int r;
	node(){
		
	}
	node(int a,int b,int c){
		x=a;
		y=b;
		r=c;
	}
};
vector<node>V;
int is_ok(int x,int y,int d){
	if(x+d>n||x-d<=0||y+d>m||y-d<=0) return 0;
	return 1;
}
int main(){
	scanf("%d %d",&n,&m);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j]; 
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int cnt=0;
			if(a[i][j]=='*'){
				for(int d=1;;d++){
					if(is_ok(i,j,d)){
						if(a[i+d][j]=='*'&&a[i-d][j]=='*'&&a[i][j+d]=='*'&&a[i][j-d]=='*'){
							cnt++;
							vis[i+d][j]=vis[i-d][j]=vis[i][j+d]=vis[i][j-d]=1;
							vis[i][j]=1;
						}else break;
					}else break;
				}
			}
			if(cnt!=0){
				V.push_back(node(i+1,j+1,cnt));
			}
		}
	}
	bool flag=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='*'&&!vis[i][j]){
				flag=true;
				break;
			}
		}
	}
	if(flag){
		printf("-1\n");
	}else{
		printf("%d\n",V.size());
		for (int i = 0; i < V.size(); i++){
            printf("%d %d %d\n", V[i].x-1, V[i].y-1, V[i].r);
        }
	}
}
