#include<iostream>
#include<cstdio>
#define maxn 3000
using namespace std;
struct node {
	int val;
	int id;
	node() {

	}
	node(int _val,int _id) {
		val=_val;
		id=_id;
	}
};
struct my_queue {
	node q[maxn+5];
	int head,tail;
	inline void clear() {
		head=1;
		tail=0;
	}
	inline void push_back(node p) {
		q[++tail]=p;
	}
	inline void pop_back() {
		tail--;
	}
	inline void pop_front() {
		head++;
	}
	inline node front() {
		return q[head];
	}
	inline node back() {
		return q[tail];
	}
	inline bool empty() {
		return head>tail;
	}
	my_queue(){
		clear();
	} 
};
my_queue q[maxn+5];
my_queue res;
int n,m,A,B;
int g[maxn*maxn+5];
int a[maxn+5][maxn+5];
void move_queue(int pos){
	for(int i=1;i<=n;i++){
		while(!q[i].empty()&&q[i].front().id<pos-B+1) q[i].pop_front();
		while(!q[i].empty()&&q[i].back().val>=a[i][pos]) q[i].pop_back();
		q[i].push_back(node(a[i][pos],pos));
	}
}
long long calc(){
	long long ans=0;
	res.clear();
	for(int i=1;i<=A;i++){
		while(!res.empty()&&res.back().val>=q[i].front().val) res.pop_back();
		res.push_back(node(q[i].front().val,i));
	}
	ans+=res.front().val;
	for(int i=A+1;i<=n;i++){
		while(!res.empty()&&res.front().id<i-A+1) res.pop_front();
		while(!res.empty()&&res.back().val>=q[i].front().val) res.pop_back();
		res.push_back(node(q[i].front().val,i));
		ans+=res.front().val;
	} 
	return ans;
}
int main() {
	int x,y,z;
	scanf("%d %d %d %d",&n,&m,&A,&B);
	scanf("%d %d %d %d",&g[1],&x,&y,&z);
	for(int i=2;i<=n*m;i++){
		g[i]=((long long)g[i-1]*x%z+y)%z;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=g[(i-1)*m+j];	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=B;j++){
			while(!q[i].empty()&&q[i].back().val>=a[i][j]) q[i].pop_back();
			q[i].push_back(node(a[i][j],j));
		}
	} 
	long long ans=0;
	ans+=calc();
	for(int i=B+1;i<=m;i++){
		move_queue(i);
		ans+=calc(); 
	}
	printf("%I64d\n",ans);
}

