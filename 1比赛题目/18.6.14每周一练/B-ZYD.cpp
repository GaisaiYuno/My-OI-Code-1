#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int Size=100001;
vector<int> to[Size];
bool vis[Size][2];
bool flag=false,win=false;
struct node {
	int father,x,y,t;
} w[Size*20];
int n,m,head,tail,last,pos;
void PushQueue(int fx,int x,int y,int t) {
	tail++;
	w[tail].x=x;
	w[tail].y=y;
	w[tail].father=fx;
	w[tail].t=t;
	vis[x][y]=true;
}
void bfs(int x) {
	PushQueue(0,x,1,0);
	while(head<tail) {
		head++;
		int len=to[w[head].x].size();
		if(!len) {
			win=!w[head].y;
			last=head;
			if(w[head].t>1e6)	flag=true;
			if(win)	return;
		}
		for(int i=len-1; i>=0; i--) {
			if(!vis[to[w[head].x][i]][!w[head].y]) {
				PushQueue(head,to[w[head].x][i],!w[head].y,w[head].t+1);
			}
		}
	}
}
void Out(int x) {
	if(x)	Out(w[x].father);
	if(x)	printf("%d ",w[x].x);
}
int go[Size];
bool dfs(int x) {
	go[x]=1;
	int len=to[x].size();
	for(int i=0; i<len; i++) {
		if(go[to[x][i]]==1) {
			return true;
		} else if(!go[to[x][i]]) {
			if(dfs(to[x][i]))	return 1;
		} else {
			continue;
		}
	}
	go[x]=-1;
	return false;
}
void Out() {
	
}
int main() {
	n=read();
	m=read();
	for(int i=1; i<=n; i++) {
		int l=read(),tmp;
		while(l--) {
			tmp=read();
			to[i].push_back(tmp);
		}
	}
	int s=read();
	bfs(s);
	if(win) {
		puts("Win");
		Out(last);
	} else if(flag || dfs(s)) {
		puts("Draw");
	} else {
		puts("Lose");
	}
	return 0;
}
