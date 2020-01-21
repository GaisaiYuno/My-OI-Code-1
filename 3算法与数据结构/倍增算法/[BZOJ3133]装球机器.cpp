//http://119.29.55.79/contest/98/problem/6
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<algorithm>
#define maxn 100000
#define maxlogn 21 
using namespace std;
int n,m;
int root;
vector<int>E[maxn+5];

int log2n;
int min_id[maxn+5];//子树中节点的最小编号 
int anc[maxn+5][maxlogn+5];
int deep[maxn+5];
bool cmp(int x,int y){
	return min_id[x]<min_id[y];
}
void dfs1(int x,int fa){
	min_id[x]=x;
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=0;i<(int)E[x].size();i++){
		int y=E[x][i];
		if(y!=fa){
			dfs1(y,x);
			min_id[x]=min(min_id[x],min_id[y]);
		}
	} 
}

int tim;
int seq[maxn+5]; //掉球顺序 
int hash_seq[maxn+5];//seq=i的节点编号 
int is_ball[maxn+5];//是否有球 
priority_queue<int,vector<int>,greater<int> >q;//按落球顺序从小到大，存储没有球的节点 
void dfs2(int x,int fa){
	for(int i=0;i<(int)E[x].size();i++){
		int y=E[x][i];
		if(y!=fa){
			dfs2(y,x);
		}
	} 
	seq[x]=++tim;
	hash_seq[seq[x]]=x;
}

int insert(int num){
	int ans;
	for(int i=1;i<=num;i++){
		int x=hash_seq[q.top()];
		q.pop();
		is_ball[x]=1;
		if(i==num){
			ans=x;
			break;
		} 
	}
	return ans;
}
int del(int x){
	int orig_x=x;
	for(int i=log2n;i>=0;i--){
		if(is_ball[anc[x][i]]) x=anc[x][i];
	}
	is_ball[x]=0;
	q.push(seq[x]);
	return deep[orig_x]-deep[x];
}

int main(){
	int f;
	int op,num;
	scanf("%d %d",&n,&m);
	log2n=log2(n)+1;
	for(int i=1;i<=n;i++){
		scanf("%d",&f);
		if(f==0) root=i;
		else E[f].push_back(i);
	} 
	dfs1(root,0);
	for(int i=1;i<=n;i++) sort(E[i].begin(),E[i].end(),cmp);
	dfs2(root,0);
	for(int i=1;i<=n;i++) q.push(seq[i]);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&op,&num);
		if(op==1) printf("%d\n",insert(num));
		else printf("%d\n",del(num));
	}
}

