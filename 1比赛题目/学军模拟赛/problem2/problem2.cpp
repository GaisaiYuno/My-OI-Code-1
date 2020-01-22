#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<list>
#define maxn 1000000
#define mod 1000000007
using namespace std;
typedef long long ll;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(ll x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
struct my_deque{
	struct node{
		ll val;
		node *pre;
		node *nex;
	};
	int sz;
	node *head=NULL,*tail=NULL;
	inline int size(){
		return sz;
	}
	bool empty(){
		return sz==0;
	}
	inline ll front(){
		return head->val;
	}
	inline ll back(){
		return tail->val;
	}
	void push_front(ll val){
		node* p=new node();
		p->val=val;
		p->pre=NULL;
		p->nex=head;
		if(head!=NULL) head->pre=p;
		head=p;
		if(tail==NULL) tail=p;
		sz++;
	}
	void push_back(ll val){
		node *p=new node();
		p->val=val;
		p->pre=tail;
		p->nex=NULL;
		if(tail!=NULL) tail->nex=p;
		tail=p;
		if(head==NULL) head=p;
		sz++;
	}
	void pop_front(){
		node *p=head->nex,*tmp=head;
		if(p!=NULL) p->pre=NULL;
		delete tmp;
		head=p;
		sz--;
	}
	void pop_back(){
		node *p=tail->pre,*tmp=tail;
		if(p!=NULL) p->nex=NULL;
		delete tmp;
		tail=p;
		sz--;
	}
	int clear(){
		sz=0;
		head=NULL;
		tail=NULL;
	}
};

my_deque q[maxn+5];
ll mark[maxn+5];
int id[maxn+5];

inline void insert_left(int pos,int x){
	q[id[pos]].push_front((x-mark[id[pos]]+mod)%mod);
}
inline ll query_left(int pos){
	pos=id[pos];
	ll ans=q[pos].front();
	ans=(ans+mark[pos]+mod)%mod;
	q[pos].pop_front();
	return ans;
}
inline void insert_right(int pos,int x){
	q[id[pos]].push_back((x-mark[id[pos]]+mod)%mod);
}
inline ll query_right(int pos){
	pos=id[pos];
	ll ans=q[pos].back();
	ans=(ans+mark[pos]+mod)%mod;
	q[pos].pop_back();
	return ans;
}
inline void add(int pos,int x){
	mark[id[pos]]+=x;
	mark[id[pos]]=(mark[id[pos]]+mod)%mod;
}
void merge(int x,int y){
//	if(q[id[x]].empty()||q[id[y]].empty()) return;
	if(q[id[x]].size()<q[id[y]].size()){
		while(!q[id[x]].empty()){
			int v=q[id[x]].back();
			q[id[x]].pop_back();
			v=(v+mark[id[x]]-mark[id[y]]+mod+mod)%mod;
			q[id[y]].push_front(v);
		}
		q[id[y]].clear();
		mark[id[x]]=0;
		swap(id[x],id[y]);
	}else{
		while(!q[id[y]].empty()){
			int v=q[id[y]].front();
			q[id[y]].pop_front();
			v=(v+mark[id[y]]-mark[id[x]]+mod+mod)%mod;
			q[id[x]].push_back(v);
		}
		q[id[y]].clear();
		mark[id[y]]=0;
	}
}


int main(){
//	freopen("input.txt","r",stdin);
//	freopen("myans.txt","w",stdout);
	freopen("problem2.in","r",stdin);
	freopen("problem2.out","w",stdout);
	int cmd,pos,x,y;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++) id[i]=i;
	for(int i=1;i<=m;i++){
		qread(cmd);
		if(cmd==1){
			qread(pos);
			qread(x);
			insert_left(pos,x);
		}else if(cmd==2){
			qread(pos);
			qprint((query_left(pos)+mod)%mod);
			putchar('\n');
		}else if(cmd==3){
			qread(pos);
			qread(x);
			insert_right(pos,x);
		}else if(cmd==4){
			qread(pos);
			qprint((query_right(pos)+mod)%mod);
			putchar('\n');
		}else if(cmd==5){
			qread(pos);
			qread(x);
			if(q[id[pos]].size())add(pos,x);
		}else{
			qread(x);
			qread(y);
			merge(x,y);
		}	
	}
}
/*
2 10
1 1 100
3 1 200
3 2 10
1 2 20
5 2 40
6 1 2
2 1
2 1
2 1
2 1
*/
