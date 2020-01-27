#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define maxm 100005
#define maxn 1005
using namespace std;
int n,m;
struct edge {
	int from;
	int to;
	int next;
} E[maxm];
int head[maxn];
int sz=0;
void add_edge(int u,int v) {
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int in[maxn],out[maxn];
int tmp[maxn];
int used[maxn];
set<int>S; 
vector<int>seq;
queue<int>q;
void init() {
	sz=0;
	memset(head,0,sizeof(head));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	memset(E,0,sizeof(E));
}
int topo_sort() {
	bool flag=true;
	memset(used,0,sizeof(used));
	int cnt=0;
	int cnt2=0; 
	seq.clear();
	while(!q.empty()) q.pop();
	for(int i=1; i<=n; i++) {
		tmp[i]=in[i];
		used[i]=0;
		if(tmp[i]==0&&out[i]!=0) {
			q.push(i);
			cnt++;
		}
	}
	if(cnt==0) return -1;
	if(cnt>1) flag=false;
	int x,y;
	while(!q.empty()) {
		x=q.front();
		q.pop();
		cnt=0;
		cnt2++;
		used[x]=1;
		seq.push_back(x);
		for(int i=head[x]; i; i=E[i].next) {
			int y=E[i].to;
			if(!used[y]) {
				tmp[y]--;
				if(tmp[y]==0) {
					q.push(y);
					cnt++;
				}
			}
		}
		if(cnt>1) flag=false;
	}
	if(cnt2!=S.size()) return -1;
	if(flag&&seq.size()==n) return 1;
	else return 0;
}

char str[4];
int main() {
	int u,v;
	int flag=0;
	bool is_ok=false;
	while(scanf("%d %d",&n,&m)!=EOF) {
		if(n==0&&m==0) break;
		init();
		is_ok=false;
		S.clear();
		for(int i=1; i<=m; i++) {
			scanf("%s",str);
			if(is_ok) continue;
			u=str[0]-'A'+1;
			v=str[2]-'A'+1;
			add_edge(u,v);
			S.insert(u);
			S.insert(v);
			in[v]++;
			out[u]++;
			flag=topo_sort();
			if(flag==1) {
				printf("Sorted sequence determined after %d relations: ",i);
				int siz=seq.size();
				for(int i=0; i<siz; i++) {
					printf("%c",seq[i]+'A'-1);
				}
				printf(".\n");
				is_ok=true;
			} else if(flag==-1) {
				printf("Inconsistency found after %d relations.\n",i);
				is_ok=true;
			}
		}
		if(flag==0) printf("Sorted sequence cannot be determined.\n");
	}

}
