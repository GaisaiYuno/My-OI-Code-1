#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 50005 
#define maxm 200005
using namespace std;
int n,m;
inline int qread() {
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
char pri[20];
inline void qprint(int x) {
	if(x==0) {
		putchar('0');
	} else {
		int ptr=0;
		while(x>0) {
			pri[++ptr]=x%10+'0';
			x/=10;
		}
		for(int i=ptr; i>=1; i--) {
			putchar(pri[i]);
		}
	}
	putchar('\n');
}

vector<int>E[maxn];
void add_edge(int u,int v) {
	E[u].push_back(v);
}
int in[maxn];//��� 
int out[maxn];//���� 
int vis[maxn];//ÿ����ķ��ʴ��� 
int f[maxn];//ɾ���õ����ɾ�������·��ĵ� ������lca 
int tot=0;
int topo_seq[maxn];//������ 
int ans[maxn];
queue<int>q;
void topo_sort() {//�������� 
	for(int i=1; i<=n; i++) {
		if(in[i]==0)q.push(i);
	}
	int x,y;
	while(!q.empty()) {
		x=q.front();
		q.pop();
		topo_seq[++tot]=x;
		int t=E[x].size();
		for(int i=0;i<t;i++) {
			y=E[x][i];
			in[y]--;
			if(in[y]==0) {
				q.push(y);
			}
		}
	}
}

int get_f(int x) {
	memset(vis,0,sizeof(vis));
	if(E[x].size()==0) return 0;
	int t=E[x].size();
	for(int i=1;i<E[x].size();i++) {//����һ���ߣ��������ıߵݹ�ȥɾ�ڵ㣬��¼������� 
		int y=E[x][i];
		while(y) {
			vis[y]++;
			y=f[y];//ֱ�������� 
		}
	}
	int y=E[x][0];
	while(y) {
		if(vis[y]+1==E[x].size()) return y;
		//���y���ʴ���(����x���һ����)+1=x���������x�����������·�������Ե�������� ��˵��ɾx��һ������ɾ��y
		//����Ϊ���������п�ǰ���������ֱ�ӷ��� 
		y=f[y];
	}
	return 0;
}
int main() {
	int x;
	n=qread();
	for(int i=1;i<=n;i++){
		while(1){
			x=qread();
			if(x==0) break;
			add_edge(i,x);
			in[x]++;
			out[i]++;
		}
	}
	topo_sort();//���������򣬴�ʱ1�Žڵ�ᱻ�ŵ���� 
	for(int i=n;i>=1;i--){//���������������ϵ��´��� 
		f[topo_seq[i]]=get_f(topo_seq[i]);
	}
	for(int i=1;i<=n;i++){//����������µ��ϸ��� 
		ans[f[topo_seq[i]]]+=ans[topo_seq[i]]+1;
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
}
