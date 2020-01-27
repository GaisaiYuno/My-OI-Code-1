#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100000
#define maxm 100000
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
inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
int a[maxn+5];
vector<int>E1[maxn+5],E2[maxn+5];
vector<int>num[maxn+5];//存储第x个块的值
void vec_insert(vector<int>&x,int y){//插入y，且不破坏从小到大的序列 
	vector<int>::iterator it=lower_bound(x.begin(),x.end(),y+1);
	if(it==x.end()) x.push_back(y);
	else x.insert(it,y);
}
void vec_del(vector<int>&x,int y){//删除y 
	vector<int>::iterator it=lower_bound(x.begin(),x.end(),y);
	if(it!=x.end()) x.erase(it);
}
void vec_modify(vector<int>&x,int last,int now){//把last修改成now 
	vec_del(x,last);
	vec_insert(x,now);
}


void add_edge(vector<int>* E,int x,int y){
	E[x].push_back(y);
} 
void del_edge(vector<int>*E,int x,int y){
	vec_del(E[x],y);
}

int bcnt=0;//块的数量
int bsz;//设定的块大小 
int bel[maxn+5];//x属于哪个块 
int fa[maxn+5];//节点x的父亲 
int root[maxn+5];//第x块对应的子树的根 
void dfs1(int x,int f){
	fa[x]=f;
	bel[x]=bcnt;
	vec_insert(num[bel[x]],a[x]);
	for(int y : E1[x]){
		if(y!=f){
			if((int)num[bel[x]].size()==bsz){
				bcnt++;
				root[bcnt]=y; 
				add_edge(E2,bel[x],bcnt);
			}
			dfs1(y,x);
		}
	}
}

int ans=0;
int get_ans(int id,int val){
	return num[id].end()-upper_bound(num[id].begin(),num[id].end(),val);
} 
void dfs2(int idx,int val){//处理整块子树 
	ans+=get_ans(idx,val);
	for(int y : E2[idx]){
		dfs2(y,val);
	} 
}
void dfs3(int x,int val){
	if(a[x]>val) ans++;//处理散点 
	for(int y : E1[x]){
		if(y!=fa[x]){
			if(bel[x]==bel[y]) dfs3(y,val);
			else dfs2(bel[y],val);
		}
	}
}

vector<int>nd;//需要重构的点 
vector<int>bk;//需要重构的块 
void dfs4(int x){
	nd.push_back(x);
	for(int y : E1[x]){
		if(y!=fa[x]){
			if(bel[y]==bel[x]) dfs4(y);
			else bk.push_back(bel[y]);
		} 
	}
}
int query(int x,int val){
	ans=0;
	if(root[bel[x]]==x) dfs2(bel[x],val);
	else dfs3(x,val);
	return ans;
}
void change_val(int x,int val){
	vec_modify(num[bel[x]],a[x],val);
	a[x]=val;
}
void add_point(int f,int val){
	a[++n]=val;
	add_edge(E1,f,n);
	add_edge(E1,n,f);
	fa[n]=f;
	if((int)num[bel[f]].size()==bsz){//如果大小超过bsz,就新建一块 
		bel[n]=++bcnt;
		root[bcnt]=n;
		vec_insert(num[bel[n]],a[n]);
		add_edge(E2,bel[f],bel[n]);
	}else{//否则插入 
		bel[n]=bel[f];
		vec_insert(num[bel[n]],a[n]); 
	}
}

void split(int x){
	if(root[bel[x]]==x){//正好自成一块 
		if(fa[x]){
			del_edge(E1,x,fa[x]);
			del_edge(E1,fa[x],x);
			del_edge(E2,bel[fa[x]],bel[x]);
		}
	}else{
		del_edge(E1,x,fa[x]);
		del_edge(E1,fa[x],x);
		bk.clear();
		nd.clear();
		dfs4(x);
		vec_del(num[bel[x]],a[x]);
		bel[x]=++bcnt;
		vec_insert(num[bel[x]],a[x]);
		for(int u : nd){
			if(u==x) continue;
			vec_del(num[bel[u]],a[u]);
			vec_insert(num[bcnt],a[u]);
			bel[u]=bcnt;
		}
		for(int t : bk){
			del_edge(E2,bel[fa[x]],t);
			add_edge(E2,bcnt,t);
		}
	} 
}
int main(){
	int cmd;
	int x,y;
	int last=0;
	qread(n);
	bsz=sqrt(n)*log(n);
	for(int i=1;i<n;i++){
		qread(x);
		qread(y);
		add_edge(E1,x,y);
		add_edge(E1,y,x);
	}
	for(int i=1;i<=n;i++) qread(a[i]);
	bcnt=1;
	root[1]=1;
	dfs1(1,0);
	qread(m);
	for(int i=1;i<=m;i++){
		qread(cmd);
		if(cmd==0){
			qread(x);
			qread(y);
			x^=last;
			y^=last;
			last=query(x,y);
			qprint(last);
			putchar('\n');
		}else if(cmd==1){
			qread(x);
			qread(y);
			x^=last;
			y^=last;
			change_val(x,y);
		}else if(cmd==2){
			qread(x);
			qread(y);
			x^=last;
			y^=last;
			add_point(x,y); 
		}else{
			qread(x);
			x^=last;
			split(x);
		}
	}
}

