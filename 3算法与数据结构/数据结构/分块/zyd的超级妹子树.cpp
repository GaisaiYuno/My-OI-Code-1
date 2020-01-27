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
vector<int>num[maxn+5];//�洢��x�����ֵ
void vec_insert(vector<int>&x,int y){//����y���Ҳ��ƻ���С��������� 
	vector<int>::iterator it=lower_bound(x.begin(),x.end(),y+1);
	if(it==x.end()) x.push_back(y);
	else x.insert(it,y);
}
void vec_del(vector<int>&x,int y){//ɾ��y 
	vector<int>::iterator it=lower_bound(x.begin(),x.end(),y);
	if(it!=x.end()) x.erase(it);
}
void vec_modify(vector<int>&x,int last,int now){//��last�޸ĳ�now 
	vec_del(x,last);
	vec_insert(x,now);
}


void add_edge(vector<int>* E,int x,int y){
	E[x].push_back(y);
} 
void del_edge(vector<int>*E,int x,int y){
	vec_del(E[x],y);
}

int bcnt=0;//�������
int bsz;//�趨�Ŀ��С 
int bel[maxn+5];//x�����ĸ��� 
int fa[maxn+5];//�ڵ�x�ĸ��� 
int root[maxn+5];//��x���Ӧ�������ĸ� 
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
void dfs2(int idx,int val){//������������ 
	ans+=get_ans(idx,val);
	for(int y : E2[idx]){
		dfs2(y,val);
	} 
}
void dfs3(int x,int val){
	if(a[x]>val) ans++;//����ɢ�� 
	for(int y : E1[x]){
		if(y!=fa[x]){
			if(bel[x]==bel[y]) dfs3(y,val);
			else dfs2(bel[y],val);
		}
	}
}

vector<int>nd;//��Ҫ�ع��ĵ� 
vector<int>bk;//��Ҫ�ع��Ŀ� 
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
	if((int)num[bel[f]].size()==bsz){//�����С����bsz,���½�һ�� 
		bel[n]=++bcnt;
		root[bcnt]=n;
		vec_insert(num[bel[n]],a[n]);
		add_edge(E2,bel[f],bel[n]);
	}else{//������� 
		bel[n]=bel[f];
		vec_insert(num[bel[n]],a[n]); 
	}
}

void split(int x){
	if(root[bel[x]]==x){//�����Գ�һ�� 
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

