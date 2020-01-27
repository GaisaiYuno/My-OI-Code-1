//https://www.luogu.com.cn/problem/P5763 
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
