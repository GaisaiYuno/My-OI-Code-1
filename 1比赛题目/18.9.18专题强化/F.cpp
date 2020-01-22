#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 1005
#define maxm 200005
using namespace std;
inline int qread(){
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
int n,m; 
int s[maxm],e[maxm];
vector<int>E[maxn];
void add_edge(int u,int v){
	E[u].push_back(v);
}
int used[maxn];
int route[maxn][maxn];
void dfs(int s,int x){
	int y;
	used[x]=1;
	route[s][x]++;
	int cnt=E[x].size();
	for(int i=0;i<cnt;i++){
		y=E[x][i];
		if(y==s) continue;
		if(!used[y]&&route[s][y]<2){
			dfs(s,y);
		}
	}
}

int judge(int u,int v){//1为diff,0为same 
	if(route[v][u]>0){//在一个SCC中 
		if(route[u][v]>=2) return 0;
		else return 1; 
	}else{//不在一个SCC中 
		if(route[u][v]>=2) return 1;
		else return 0;
	}
}

char a[]="same",b[]="diff";
void qprint(char *s,int len){
	for(int i=0;i<len;i++){
		putchar(s[i]);
	}
	putchar('\n');
}
int main(){
//	scanf("%d %d",&n,&m);
	n=qread();
	m=qread(); 
	int u,v;
	for(int i=1;i<=m;i++){
//		scanf("%d %d",&u,&v);
		s[i]=qread();
		e[i]=qread();
		add_edge(s[i],e[i]);
	}
	int y;
	for(int i=1;i<=n;i++){
		int cnt=E[i].size();
		for(int j=0;j<cnt;j++){
			y=E[i][j];
			if(route[i][y]<2){
				memset(used,0,sizeof(used));
				dfs(i,y);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%d ",route[i][j]);
//		}
//		printf("\n");
//	}
	for(int i=1;i<=m;i++){
		if(judge(s[i],e[i]) )qprint(b,4);
		else qprint(a,4);
	}
}
