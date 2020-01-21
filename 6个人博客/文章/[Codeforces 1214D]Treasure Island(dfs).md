## [Codeforces 1214D]Treasure Island(dfs)

### 题面

给出一个n*m的字符矩阵，'.'表示能通过，'#'表示不能通过。每步可以往下或往右走。问至少把多少个'.'变成'#'，才能让从(1,1)出发不能到达(n,m)

$n \times m \leq 10^6$

### 分析

第一眼还以为是最小割，一看数据范围感觉会TLE。实际上搜索就可以了。

首先发现答案肯定是0,1,2中的一个(~~输出rand()%3~~),因为最多用2个'#',把(1,1)右侧和下方堵住就可以了。

然后注意到若存在一个点满足所有(1,1)到(n,m)的路径都经过那个点，那答案就为1.这实际上是一个有向图求割点的问题，类似HDU3313.

我们只需要dfs一遍，找出任意一条(1,1)到(n,m)的路径，然后把路径上的点标记为1。注意若(1,1)不能到(n,m)，直接输出0.第二次dfs保证不经过路径上的点。如果第二次的时候(1,1)不能到(n,m)，那就说明存在割点，答案为1。否则答案为2.

注意到数据范围$n \times m \leq 10^6$，没有给出n,m的范围，所以要用vector存储字符矩阵。

###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1000000
using namespace std;
int n,m;
char in[maxn+5];
vector<char>s[maxn+5];
struct node{
	int x;
	int y;
	node(){
		
	}
	node(int _x,int _y){
		x=_x;
		y=_y;
	}
};
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
vector<bool>vis[maxn+5];
vector<bool>mark[maxn+5];
bool dfs(int x,int y){
	if(x>n||y>m) return 0;
	if(x==n&&y==m) return 1;
	if(s[x][y]=='#'||vis[x][y]||mark[x][y]) return 0;
	vis[x][y]=1;
	bool flag=dfs(x+1,y);
	if(!flag) flag=dfs(x,y+1);
	if(flag) mark[x][y]=1;
	return flag;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",in+1);
		s[i].resize(m+1);
		for(int j=1;j<=m;j++) s[i][j]=in[j];
		vis[i].resize(m+1);
		mark[i].resize(m+1); 
	}
	bool flag=dfs(1,1);
	if(!flag) printf("0\n");
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) vis[i][j]=0;
		}
		mark[1][1]=mark[n][m]=0;
		flag=dfs(1,1);
		if(!flag) printf("1\n");
		else printf("2\n");
	}
		
}

```

