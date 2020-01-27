#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#define maxn 500000
#define maxm 500000
#define maxlogn 25
using namespace std;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(long long x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}


int n,m,q;

struct graph {//��װͼ 
	struct edge {
		int from;
		int to;
		int next;
	} E[maxm*2+5];
	int nodes[maxn+5];
	//�洢�ڵ��ţ��������Խ�Լ����ͼ�нڵ��ʱ�䣬���ô�1~n�������ᱻ����O(n^2)),ֻ��Ҫ����nodes�нڵ� 
	int head[maxn+5];
	int esz;
	int vsz;
	void add_node(int x) {
		vsz++;
		nodes[vsz]=x;
	}
	void unique_node() {
		sort(nodes+1,nodes+1+vsz);
		vsz=unique(nodes+1,nodes+1+vsz)-nodes-1;
	}
	void add_edge(int u,int v) {
		esz++;
		E[esz].from=u;
		E[esz].to=v;
		E[esz].next=head[u];
		head[u]=esz;
	}
	graph() {
		esz=1;
	}
	void clear() { //ʹ�ú����
		esz=1;
		for(int i=1; i<=vsz; i++) head[nodes[i]]=0;
		vsz=0;
	}
	void debug() {
		printf("node=%d edge=%d\n",vsz,esz);
		for(int i=2; i<=esz; i+=2) {
			printf("debug:%d %d\n",E[i].from,E[i].to);
		}
	}
} G1,G2,G3;



namespace e_dcc {//��-˫��ͨ�������
	int tim,cnt;
	int dfn[maxn+5];
	int low[maxn+5];
	bool bridge[maxm*2+5];
	int bel[maxn+5];//�洢���ڵڼ���e-dcc
	bool vis[maxn+5];

	void tarjan(int x,int last,graph& G) {
		dfn[x]=++tim;
		low[x]=dfn[x];
		for(int i=G.head[x]; i; i=G.E[i].next) {
			int y=G.E[i].to;
			if(!dfn[y]) {
				tarjan(y,i,G);
				low[x]=min(low[x],low[y]);
				if(dfn[x]<low[y]) {
					bridge[i]=bridge[i^1]=1;
				}
			} else if(i!=(last^1)) low[x]=min(low[x],dfn[y]);
		}
	}

	void dfs_mark(int x,int col,graph& G) {//�����űߣ��������e-dcc 
		bel[x]=col;
		vis[x]=1;
		for(int i=G.head[x]; i; i=G.E[i].next) {
			int y=G.E[i].to;
			if(!vis[y]&&!bridge[i]) {
				dfs_mark(y,col,G);
			}
		}
	}

	int get_bel(graph &G) {//���v-dcc,������,����v-dcc����
		for(int i=1; i<=G.vsz; i++) {
			int u=G.nodes[i];
			low[u]=dfn[u]=bel[u]=vis[u]=0;
		}
		for(int i=1; i<=G.esz; i++) bridge[i]=0;
		tim=0;
		for(int i=1; i<=G.vsz; i++) {
			if(!dfn[G.nodes[i]]) {
				tarjan(G.nodes[i],0,G);
			}
		}

		cnt=0;
		for(int i=1; i<=G.vsz; i++) {
			if(!vis[G.nodes[i]]) {
				cnt++;
				dfs_mark(G.nodes[i],cnt,G);
			}
		}
		return cnt;
	}


	void graph_to_tree(graph &in,graph &out) {//����
		get_bel(in);
		for(int i=2; i<=in.esz; i++) {
			if(bel[in.E[i].from]!=bel[in.E[i].to]) {
				out.add_edge(bel[in.E[i].from],bel[in.E[i].to]);
			}
		}
		out.vsz=cnt;
	}
}

vector<int>nodes;//�����ϵĵ�
namespace virtual_tree {//�������
	int log2n;
	int tim=0;
	int dfn[maxn+5];
	int deep[maxn+5];
	int rt[maxn+5];
	int anc[maxn+5][maxlogn+5];
	void dfs(int x,int fa,int root,graph &T1) {
		dfn[x]=++tim;
		rt[x]=root;
		deep[x]=deep[fa]+1;
		anc[x][0]=fa;
		for(int i=1; i<=log2n; i++)anc[x][i]=anc[anc[x][i-1]][i-1];
		for(int i=T1.head[x]; i; i=T1.E[i].next) {
			int y=T1.E[i].to;
			if(y!=fa) {
				dfs(y,x,root,T1);
			}
		}
	}
	int lca(int x,int y) {
		if(deep[x]<deep[y]) swap(x,y);
		for(int i=log2n; i>=0; i--) {
			if(deep[anc[x][i]]>=deep[y]) {
				x=anc[x][i];
			}
		}
		if(x==y) return x;
		for(int i=log2n; i>=0; i--) {
			if(anc[x][i]!=anc[y][i]) {
				x=anc[x][i];
				y=anc[y][i];
			}
		}
		return anc[x][0];
	}


	int top=0;
	int s[maxn];
	int in[maxn];
	int cmp(int x,int y) {
		return dfn[x]<dfn[y];
	}


	void insert(int x,graph &T2) {//��������ģ�� 
		if(top<1) {
			s[++top]=x;
			return;
		}
		int lc=lca(x,s[top]);
		if(lc==s[top]) {
			s[++top]=x;
			return;
		}
		while(top>1&&deep[s[top-1]]>=deep[lc]) {
			T2.add_edge(s[top-1],s[top]);
			T2.add_edge(s[top],s[top-1]);
			T2.add_node(s[top]);
			T2.add_node(s[top-1]);
			top--;
		}
		if(s[top]!=lc) {
			T2.add_edge(lc,s[top]);
			T2.add_edge(s[top],lc);
			T2.add_node(lc);
			T2.add_node(s[top]);
		}
		s[top]=lc;
		s[++top]=x;
	}

	void ini_tree(graph &in) { //��ʼ��ԭ����ɭ��
		log2n=log2(in.vsz)+1;
		for(int i=1; i<=in.vsz; i++) {
			if(!deep[i]) dfs(i,0,i,in);
		}
	}

	void get_vir_tree(int *in,int k,graph &out) { //����ÿ��ѯ��,��������
		sort(in+1,in+1+k,cmp);
		int r;
		for(int l=1; l<=k; l=r+1) {
			//ע�ⲻһ��ֻ��һ����������dfn�����
			//rt[i]Ϊ��i��������ı�� 
			//[l,r]��Ӧ����������ͬһ���������� 
			r=l;
			while(r<k&&rt[in[r]]==rt[in[r+1]]) r++;//�ҳ���һ������ĵ�
			top=0;
			for(int i=l; i<=r; i++) {
				insert(in[i],out);
			}
			while(top>1) {
				out.add_edge(s[top-1],s[top]);
				out.add_edge(s[top],s[top-1]);
				out.add_node(s[top-1]);
				out.add_node(s[top]);
				top--;
			}
			if(l==r) out.add_node(in[l]); //ֻ��һ��������� 
		}


	}
}

int org_bel[maxn+5];//��x��ԭͼG1�е�e-dcc���,����namespace��Ĳ����ڱ䣬Ҫ����һ��

int org_point[maxn+5]; //ѯ�ʵĵ� 
int point[maxn+5];//�����������ĵ� 
bool check(int tn){//���ѯ�ʵĵ��Ƿ���ͬһ��e-dcc�� 
	for(int i=2;i<=tn;i++){
		if(e_dcc::bel[org_point[i]]!=e_dcc::bel[org_point[1]]) return 0;
	}
	return 1;
}
int main() {
	int u,v;
	qread(n);
	qread(m);
	qread(q);
	for(int i=1; i<=n; i++) G1.add_node(i);
	for(int i=1; i<=m; i++) {
		qread(u);
		qread(v);
		G1.add_edge(u,v);
		G1.add_edge(v,u);
	}

	e_dcc::graph_to_tree(G1,G2);
	for(int i=1; i<=n; i++) {
		org_bel[i]=e_dcc::bel[i];

	}
	virtual_tree::ini_tree(G2);

	int rcnt=0;
	int tn,tm,tsz;
	for(int i=1; i<=q; i++) {
		qread(tn);
		qread(tm);
		tsz=0;
		for(int j=1; j<=tn; j++) {
			qread(org_point[j]);
			org_point[j]=(org_point[j]+rcnt)%n;//ǿ������
			if(org_point[j]==0) org_point[j]=n;
			org_point[j]=org_bel[org_point[j]];
			point[++tsz]=org_point[j];
		}
	
		for(int j=1; j<=tm; j++) {
			qread(u);
			qread(v);
			u=(u+rcnt)%n;
			if(u==0) u=n;
			v=(v+rcnt)%n;
			if(v==0) v=n;
			if(org_bel[v]!=org_bel[u]) {
				G3.add_edge(org_bel[u],org_bel[v]);
				G3.add_edge(org_bel[v],org_bel[u]);
				G3.add_node(org_bel[u]);
				G3.add_node(org_bel[v]);
			}
			point[++tsz]=org_bel[u];
			point[++tsz]=org_bel[v];//���ϵĵ�ҲҪ�ӽ�ȥ������
		}

		sort(point+1,point+1+tsz);
		tsz=unique(point+1,point+1+tsz)-point-1;
		virtual_tree::get_vir_tree(point,tsz,G3);
		G3.unique_node();
#ifdef DEBUG 
		G3.debug();
#endif
		e_dcc::get_bel(G3);
		if(tn==1||check(tn)) {//��һ��ֻ��1��e-dcc��ֻҪѯ�ʵ�tn������һ��e-dcc�� 
			printf("YES\n");
			rcnt+=i;//�Ǽ��ϴ𰸱�ţ�����+1 
			rcnt%=n; //��ֹ��int 
		} else {
			printf("NO\n");
		}

		G3.clear();//�������
	}
}

