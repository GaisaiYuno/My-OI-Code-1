## [BZOJ 3117] [NOI1999]内存分配(STL)

### 题面

内存是计算机重要的资源之一，程序运行的过程中必须对内存进行分配。 经典的内存分配过程是这样进行的：

1.内存以内存单元为基本单位，每个内存单元用一个固定的整数作为标识，称为地址。地址从0开始连续排列，地址相邻的内存单元被认为是逻辑上连续的。我们把从地址i开始的s个连续的内存单元称为首地址为i长度为s的地址片。

2.运行过程中有若干进程需要占用内存，对于每个进程有一个申请时刻T，需要内存单元数M及运行时间P。在运行时间P内（即T时刻开始，T+P时刻结束），这M个被占用的内存单元不能再被其他进程使用。

3.假设在T时刻有一个进程申请M个单元，且运行时间为P，则：

- 若T时刻内存中存在长度为M的空闲地址片，则系统将这M个空闲单元分配给该进程。若存在多个长度为M个空闲地址片，则系统将首地址最小的那个空闲地址片分配给该进程。
- 如果T时刻不存在长度为M的空闲地址片，则该进程被放入一个等待队列。对于处于等待队列队头的进程，只要在任一时刻，存在长度为M的空闲地址片，系统马上将该进程取出队列，并为它分配内存单元。注意，在进行内存分配处理过程中，处于等待队列队头的进程的处理优先级最高，队列中的其它进程不能先于队头进程被处理。

现在给出一系列描述进程的数据，请编写一程序模拟系统分配内存的过程。

### 分析

用一个``set``维护内存，每个元素是一个区间，表示连续的空闲内存。分配一段内存的时候需要修改区间端点。而释放内存的时候除了要将一个新的区间插入之外，如果和左边和右边的区间是连续的，还需要合并。因为插入之前区间一定不连续，所以只需要合并2次，复杂度$O(\log n)$

```cpp
typedef set< pair<int,int> >sp;
typedef sp::iterator spi;
sp mem;
void new_mem(spi it,int sz){
	int l=it->first,r=it->second;
	mem.erase(it);
	if(l+sz<=r){
		mem.insert(make_pair(l+sz,r));
	}
}
void free_mem(pair<int,int>x) {
	if(mem.empty()){
		mem.insert(x);
		return; 
	}
	 spi pre=mem.lower_bound(x);
	 if(pre!=mem.begin()) pre--;
	 if(pre->second+1==x.first){
	 	int newl=pre->first;
	 	mem.erase(pre);
	 	pre=mem.insert(make_pair(newl,x.second)).first;
	 	//insert返回插入的位置 
		//利用insert的返回值，找到合并后的区间，方便第二次合并 
	 }else pre=mem.insert(x).first;
	 spi nex=mem.upper_bound(x);
	 if(nex!=mem.end()&&x.second+1==nex->first){
	 	int newl=pre->first;
	 	int newr=nex->second;
	 	mem.erase(pre);
	 	mem.erase(nex);
	 	mem.insert(make_pair(newl,newr));
	 }
}
```

查找空闲内存的时候暴力遍历整个set,复杂度O(能过)。

-----



用```priority_queue```维护的当前正在运行的进程,按照结束时间从小到大排序。

```cpp
struct task {
	ll st;//开始时间
	ll ed;//结束时间
	int space;//内存大小
	pair<int,int>p;//占用的内存区间
	task() {

	}
	task(ll _st,ll _ed,int _space,pair<int,int>_p) {
		st=_st;
		ed=_ed;
		space=_space;
		p=_p;
	}
	friend bool operator < (task p,task q) {
		return p.ed>q.ed;
	}
};
priority_queue<task>now_run;
```

-----

等待队列直接用一个```queue```维护就好了。

-----

每当一个进程请求内存的时候。先把正在运行的进程中，结束时间<请求时间的内存释放。等同一时刻结束的进程结束后，再处理等待队列。然后尝试把当前进程添加，如果空闲内存足够，则直接分配内存。否则加入等待队列。

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<utility>
#define maxm 10000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
int n;
int cnt;
struct oper {
	ll t;
	int m;
	ll p;
} a[maxm+5];

typedef set< pair<int,int> >sp;
typedef sp::iterator spi;
sp mem;
void new_mem(spi it,int sz){
	int l=it->first,r=it->second;
	mem.erase(it);
	if(l+sz<=r){
		mem.insert(make_pair(l+sz,r));
	}
}
void free_mem(pair<int,int>x) {
	if(mem.empty()){
		mem.insert(x);
		return; 
	}
	 spi pre=mem.lower_bound(x);
	 if(pre!=mem.begin()) pre--;
	 if(pre->second+1==x.first){
	 	int newl=pre->first;
	 	mem.erase(pre);
	 	pre=mem.insert(make_pair(newl,x.second)).first;
	 	//insert返回插入的位置 
		//利用insert的返回值，找到合并后的区间，方便第二次合并 
	 }else pre=mem.insert(x).first;
	 spi nex=mem.upper_bound(x);
	 if(nex!=mem.end()&&x.second+1==nex->first){
	 	int newl=pre->first;
	 	int newr=nex->second;
	 	mem.erase(pre);
	 	mem.erase(nex);
	 	mem.insert(make_pair(newl,newr));
	 }
}
pair<int,int> find_mem(int sz){
	for(spi it=mem.begin();it!=mem.end();it++){
		int l=it->first,r=it->second;
		if(r-l+1>=sz){
			new_mem(it,sz);
			return make_pair(l,l+sz-1);
		}
	}
	return make_pair(-1,-1);
}
void print_mem(){
	for(spi it=mem.begin();it!=mem.end();it++){
		int l=it->first,r=it->second;
		printf("[%d,%d] ",l,r);
	}	
	printf("\n");
} 

struct task {
	ll st;
	ll ed;
	int space;
	pair<int,int>p;
	task() {

	}
	task(ll _st,ll _ed,int _space,pair<int,int>_p) {
		st=_st;
		ed=_ed;
		space=_space;
		p=_p;
	}
	friend bool operator < (task p,task q) {
		return p.ed>q.ed;
	}
};
priority_queue<task>now_run;
queue<int>now_wait;
void pop_wait(ll tim) {
	while(!now_wait.empty()) {
		int id=now_wait.front();
		pair<int,int>tmp=find_mem(a[id].m);
		if(tmp.first!=-1) {
			now_run.push(task(tim,tim+a[id].p,a[id].m,tmp));
			now_wait.pop();
		} else break;
	}
}

ll last=0;
void free_task(ll tim) {
	while(!now_run.empty()&&now_run.top().ed<=tim) {
		task tmp=now_run.top();
		free_mem(tmp.p);
		last=max(last,tmp.ed);
		now_run.pop();
		if(now_run.empty()||now_run.top().ed!=tmp.ed) pop_wait(tmp.ed);//等同一时刻结束的进程释放后，再处理等待的 
	}
}

int inq_cnt=0;
void add_task(int id) {
	free_task(a[id].t);
	pair<int,int>tmp=find_mem(a[id].m);
	if(tmp.first!=-1) {
		now_run.push(task(a[id].t,a[id].t+a[id].p,a[id].m,tmp));
	} else {
		inq_cnt++;
		now_wait.push(id);
	}
}

int main() {
	int u,v,w;
	scanf("%d",&n);
	while(scanf("%d %d %d",&u,&v,&w)!=EOF) {
		if(u==0&&v==0&&w==0) break;
		cnt++;
		a[cnt].t=u;
		a[cnt].m=v;
		a[cnt].p=w;
	}
	mem.insert(make_pair(0,n-1));
	for(int i=1; i<=cnt; i++) {
		add_task(i);
	}
	free_task(INF);
	printf("%lld\n%d\n",last,inq_cnt);
}
```

