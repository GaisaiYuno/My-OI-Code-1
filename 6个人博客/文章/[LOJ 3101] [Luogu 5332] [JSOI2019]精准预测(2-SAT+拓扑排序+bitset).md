## [LOJ 3101] [Luogu 5332] [JSOI2019]精准预测(2-SAT+拓扑排序+bitset)

### 题面

题面较长,略

### 分析

首先，发现火星人只有死和活两种状态，考虑2-SAT

#### 建图

对于每个火星人，把它按时间和状态拆点，$(i,t,0/1)$代表第i个火星人在t时刻，0代表活，1代表死。然后按如下方法对每个火星人连边。

1.$(i,t+1,0) → (i,t,0)$,人死了不能复活，所以一个火星人t+1时刻活着，t时刻也一定活着

2.$(i,t,1) → (i,t+1,1)$,同理一个火星人t时刻死了，t+1时刻也一定死了

对于限制$0 \ t\  x\  y$，连边$(x,t,1) →(y,t+1,1) $,顺便把逆否命题连上$(y,t+1,0) →(x,t,0) $

对于限制$1 \ t\  x\  y$，连边$(x,t,0) →(y,t,1) $,顺便把逆否命题连上$(y,t,0) →(x,t,1) $

这样连边的点数是$O(nT)$级别，空间和时间复杂度都超出限制。实际上，我们发现只有在询问里提到的时间点和T+1时间点有意义，这样就可以减少点数，把总点数优化到$2m+2n$级别。具体做法是对每个人开一个vector,存储跟这个人有关的时刻。然后在vector里按顺序给点编号。如第1个人vector里有3个元素，编号为1,2,3,第2个人vector里有2个元素，编号为4,5.对于表示活的点i，它对应的死的点编号为(i+总点数)

#### 计算答案

对于每个人i来说,同时与它生还的人最多有n-1个。于是我们把问题反过来考虑，计算若i生还，则确定一定死亡的人数cnt,n-1-cnt即为答案。那么问题就转化成了选择$(i,T,0)$会有多少个$j$使得$(j,T+1,1)$被选择。在图上的意义是有多少个$(j,T+1,1)$在$(i,T,0)$的后继节点中。

容易发现，我们只会从活向死连边，或者活、死两种状态内部连边。而活、死两种状态的内部由于存在时间差，因此一定无环，也就是说我们连出来的图一定是一个DAG，2-SAT一定有解。从图的意义来讲也是这样，因为一开始所有人都死了显然是一个满足条件的解。

那么直接在DAG上按拓扑序的逆序dp即可。用bitset来优化，第x个点的bitset的第k位为1，表示它的后继节点中有节点k。

注意处理一种特殊情况,把自己活能推出自己死的矛盾点记录下来。它的最终答案一定为0，而对于其他的点，无论这些矛盾点在不在它的后继节点中，都要把这些点的数量从n-1里面减去。

#### 内存优化

直接开2(m+n)个大小为n的bitset是会MLE的，我们每一次取maxb个点做拓扑，编号映射到[1,maxb]内，然后累加答案。取maxb=10000时较优

### 代码

```cpp
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

```

