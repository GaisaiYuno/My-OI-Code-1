#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<vector>
#include<algorithm>
#include<queue>
#include<ctime>
#include<bitset>
#define maxn 50000
#define maxm 100000
#define maxb 10100
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


int T,n,m;
struct pred{
	int op;
	int t;
	int x;
	int y;
}q[maxm*4+5];

int ind[maxm*4+5];//入度，拓扑排序用 
vector<int>E[maxm*4+5];
void add_edge(int u,int v){
//	printf("db:%d %d\n",u,v);
	E[u].push_back(v);
	ind[v]++;
}
vector<int>tim[maxn+5];//存储预测里与第i个人有关的时间 
int idl[maxn+5];//第i个人不同时间点的编号的最小值
int idr[maxn+5];//第i个人不同时间点的编号的最大值

int res[maxn+5];
bitset<maxb+5>bin[maxm*4+5];//为了不MLE，每一次取maxb个点做拓扑，编号映射到[1,maxb]内 
bitset<maxb+5>tmp;
int cnt=0;
int seq[maxm*4+5];//拓扑序 
void topo_sort(){
	queue<int>q;
	for(int i=1;i<=idr[n]*2;i++){
		if(ind[i]==0) q.push(i); 
	}
	while(!q.empty()){
		int x=q.front();
		seq[++cnt]=x;
		q.pop();
		for(int y : E[x]){
			ind[y]--;
			if(ind[y]==0) q.push(y);
		}
	}
}
void calc(int l,int r){
	for(int i=cnt;i>=1;i--){
		int x=seq[i];
		for(int y : E[x]){
			bin[x]|=bin[y];
			//按拓扑序的逆序做 
		}
	}
	tmp.reset();//每次tmp都要初始化 
	for(int i=l;i<=r;i++){
		if(bin[idr[i]][i-l]){
			//把自己活能推出自己死的点x记录下来 
			res[i]=0;//x的贡献不考虑 
			tmp.set(i-l);
		}
	}
	for(int i=1;i<=n;i++){//记得从1~n开始更新 
		if(res[i]){
			res[i]-=(tmp|bin[idr[i]]).count();
			// 去掉自己活能推出自己死的点，所以要|tmp 
		}
	} 
} 
int main(){ 
	qread(T);
	qread(n);
	qread(m);
	for(int i=1;i<=m;i++){
		qread(q[i].op);
		qread(q[i].t);
		qread(q[i].x);
		qread(q[i].y);
		tim[q[i].x].push_back(q[i].t);
	} 
	for(int i=1;i<=n;i++) tim[i].push_back(T+1);
	for(int i=1;i<=n;i++){
		sort(tim[i].begin(),tim[i].end());
		tim[i].resize(unique(tim[i].begin(),tim[i].end())-tim[i].begin());
		idl[i]=idr[i-1]+1;
		idr[i]=idl[i]+tim[i].size()-1;
	} 
	//1~idr[n]为活点
	//idr[n]+1~idr[n]*2为死点 
	for(int i=1;i<=n;i++){
		for(int j=1;j<(int)tim[i].size();j++){
			int a=idl[i]+j-1;
			add_edge(a+1,a);//(i,t+1,0)->(i,t,0)
			add_edge(a+idr[n],a+1+idr[n]);//(i,t,1)->(i,t+1,1) 
		}
	}
	for(int i=1;i<=m;i++){
		int x=q[i].x;
		int y=q[i].y;
		int t=q[i].t;
		if(q[i].op==0){
			int a=lower_bound(tim[x].begin(),tim[x].end(),t)-tim[x].begin()+idl[x];
			int b=lower_bound(tim[y].begin(),tim[y].end(),t+1)-tim[y].begin()+idl[y];
			add_edge(a+idr[n],b+idr[n]);//(x,t,1)->(y,t+1,1)
			add_edge(b,a);	//(y,t+1,0)->(x,t,0) 
		}else{
			int a=lower_bound(tim[x].begin(),tim[x].end(),t)-tim[x].begin()+idl[x];
			int b=lower_bound(tim[y].begin(),tim[y].end(),t)-tim[y].begin()+idl[y];
			add_edge(a,b+idr[n]);//(x,t,0)->(y,t,1)
			add_edge(b,a+idr[n]);           //(y,t,0)->(x,t,1)
		} 
	}
	topo_sort();
	for(int i=1;i<=n;i++) res[i]=n-1;//初始的时候一共有n-1个人，等下再减掉死的 
	for(int i=1;i<=n;i+=maxb){
		for(int j=1;j<=2*idr[n];j++){
			bin[j].reset(); 
		}
		int l=i,r=min(n,i+maxb-1);
		for(int j=l;j<=r;j++) bin[idr[j]+idr[n]].set(j-l);//初始化，把死点赋值成1
		calc(l,r);
	} 
	for(int i=1;i<=n;i++){
		qprint(res[i]);
		putchar(' ');
	}
}

