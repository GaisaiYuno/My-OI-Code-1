#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
using namespace std;
int n;
struct graph {
	int a[10][10];
	graph() {
		memset(a,0,sizeof(a));
	}
	graph(int m[10][10]) {
		for(int i=0;i<5;i++) {
			for(int j=0;j<7;j++) {
				a[i][j]=m[i][j];
			}
		}
	}
	void debug() {
		for(int i=0;i<5;i++) {
			for(int j=0;j<7;j++) {
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	int empty() {
		for(int i=0;i<5;i++) {
			for(int j=0;j<7;j++) {
				if(a[i][j]!=0) return 0;
			}
		}
		return 1;
	}
	void fall(int x) { //第x行掉下去
		for(int i=1;i<7;i++) {
			if(a[x][i]==0) continue;
			int y=i;
			while(a[x][y-1]==0&&y>0) {
				a[x][y-1]=a[x][y];
				a[x][y]=0;
				y--;
			}
		}
	}
	void move(int x1,int y1,int x2,int y2) { //左右移动
		swap(a[x1][y1],a[x2][y2]);
		if(a[x1][y1]==0||a[x2][y2]==0) {
			fall(x1);
			fall(x2);
		}
	}
	int del() {
		int cls[5][7];
		int k=0;
		for(int i=0;i<5;i++) {
			for(int j=0;j<7;j++) {
				cls[i][j]=0;
			}
		}
		for(int i=0;i<5;i++) {
			int now=0;
			for(int j=1;j<7;j++) {
				if(a[i][j]==0)break;
				if(a[i][j]!=a[i][now]) {
					now=j;
					continue;
				}
				if(j-now==2) {
					k=1;
					for(int k=now;k<=j;k++)cls[i][k]=1;
				}
				if(j-now>2)cls[i][j]=1;
			}
		}
		for(int i=0;i<7;i++) {
			int now=0;
			for(int j=1;j<5;j++) {
				if(a[j][i]==0) {
					now=j-1;
					continue;
				}
				if(a[j][i]!=a[now][i]) {
					now=j;
					continue;
				}
				if(j-now==2) {
					k=1;
					for(int k=now;k<=j;k++)cls[k][i]=1;
				}
				if(j-now>2)cls[j][i]=1;
			}
		}
		if(k) {
			for(int i=0;i<5;i++) {
				int e=0;
				for(int j=0;j<7;j++) {
					if(cls[i][j]) {
						e=1;
						a[i][j]=0;
					}
				}
				if(e) fall(i);
			}
			return 1;
		}
		return 0;
	}

	friend int operator <(graph x,graph y) {
		for(int i=0;i<5;i++) {
			for(int j=0;j<7;j++) {
				if(x.a[i][j]!=y.a[i][j]) return x.a[i][j]<y.a[i][j];
			}
		}
	}
};
map<graph,int>used[10];
struct result {
	int x;
	int y;
	int g;
	result() {

	}
	result(int xx,int yy,int dir) {
		x=xx;
		y=yy;
		g=dir;
	}
};
stack<result>ans;
int dfs(int d,graph now) {
	if(n<d) return now.empty();
	now.debug(); 
//	if(used[d][now])return 0;
//	used[d][now]=1;
	graph tmp;
	for(int i=0;i<4;i++) {
		for(int j=0;j<7;j++) {
			if(now.a[i][j]==0)break;
			tmp=now;
			tmp.move(i,j,i+1,j);
			while(tmp.del());
			if(dfs(d+1,tmp)) {
				ans.push(result(i,j,1));
				return 1;
			}
			if(i==0) continue;
			if(now.a[i-1][j]==0) {
				tmp=now;
				tmp.move(i,j,i-1,j);
				while(tmp.del());
				if(dfs(d+1,tmp)) {
					ans.push(result(i,j,-1));
					return 1;
				}
			}
		}
	}
	for(int j=0;j<7;j++) {
		if(now.a[4][j]==0)break;
		if(now.a[3][j]==0) {
			tmp=now;
			tmp.move(4,j,3,j);
			while(tmp.del());
			if(dfs(d+1,tmp)) {
				ans.push(result(4,j,-1));
				return 1;
			}
		}
	}
	return 0;
}
int in[10][10];
void print_ans() {
	while(!ans.empty()) {
		result now=ans.top();
		ans.pop();
		printf("%d %d %d\n",now.x,now.y,now.g);
	}
}
int main() {
//	freopen("mayan.in","r",stdin);
//	freopen("mayan.out","w",stdout);
	scanf("%d",&n);
	int cnt=0;
	for(int i=0;i<5;i++) {
		for(int j=0;j<=7;j++) {
			scanf("%d",&in[i][j]);
			if(in[i][j]==0) {
				break;
			}
		}
	}
	if(dfs(1,graph(in))) {
		print_ans();
	} else printf("-1\n");
}
