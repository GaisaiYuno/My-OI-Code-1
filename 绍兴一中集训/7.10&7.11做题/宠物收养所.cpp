//https://vjudge.net/contest/309914 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define maxn 80000
#define mod 1000000
#define INF 0x3f3f3f3f
using namespace std;
struct treap{
	struct node{
		int ls;
		int rs;
		int val;
		int dat;
		int sz;
		int cnt;
	}tree[maxn+5];
	int ptr;
	int root;
	int New(int val){
		ptr++;
		tree[ptr].val=val;
		tree[ptr].dat=rand();
		tree[ptr].sz=tree[ptr].cnt=1;
		return ptr;
	}
	void push_up(int x){
		tree[x].sz=tree[tree[x].ls].sz+tree[tree[x].rs].sz+tree[x].cnt;
	}
	void rturn(int &x){
		int y=tree[x].ls;
		tree[x].ls=tree[y].rs;
		tree[y].rs=x;
		x=y;
		push_up(tree[x].rs);
		push_up(x);
	}
	void lturn(int &x){
		int y=tree[x].rs;
		tree[x].rs=tree[y].ls;
		tree[y].ls=x;
		x=y;
		push_up(tree[x].ls);
		push_up(x);
	}
	void insert(int &x,int val){
		if(x==0){
			x=New(val);
			return;
		}
		if(tree[x].val==val){
			tree[x].cnt++;
			push_up(x);
			return;
		}
		if(val<tree[x].val){
			insert(tree[x].ls,val);
			if(tree[x].dat<tree[tree[x].ls].dat) rturn(x);
		}
		if(val>tree[x].val){
			insert(tree[x].rs,val);
			if(tree[x].dat<tree[tree[x].rs].dat) lturn(x);
		}
		push_up(x);
	}
	int get_pre(int x,int val){
		if(x==0) return -INF;
		if(tree[x].val>=val) return get_pre(tree[x].ls,val);
		else return max(get_pre(tree[x].rs,val),tree[x].val);
	}
	int get_nex(int x,int val){
		if(x==0) return INF;
		if(tree[x].val<=val) return get_nex(tree[x].rs,val);
		else return min(get_nex(tree[x].ls,val),tree[x].val);
	}
	void del(int &x,int val){
		if(x==0) return;
		if(tree[x].val==val){
			if(tree[x].cnt>1){
				tree[x].cnt--;
				push_up(x);
				return;
			}else{
				if(tree[x].ls||tree[x].rs){
					if(tree[x].rs==0||tree[tree[x].ls].dat>tree[tree[x].rs].dat){
						rturn(x);
						del(tree[x].rs,val);
					}else{
						lturn(x);
						del(tree[x].ls,val);
					}
				}else x=0;
				return;
			}
		}
		if(val<tree[x].val){
			del(tree[x].ls,val);
		}else{
			del(tree[x].rs,val);
		}
		push_up(x);
	}
}T;

int n;
int main(){
	int cnt=0;//未被领养的狗的个数 
	int cur;//当前状态，0表示有狗未被领养 
	int x,y;
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		if(cnt==0||cur==x){
			cnt++;
			cur=x;
			T.insert(T.root,y);
		}else{
			int pre=T.get_pre(T.root,y);
			int nex=T.get_nex(T.root,y);
			long long tmp;
			if(y-pre<=nex-y){
				tmp=y-pre;
				cnt--;
				T.del(T.root,pre);
			}else{
				tmp=nex-y;
				cnt--;
				T.del(T.root,nex);
			}
			ans=(ans+tmp)%mod; 
		}
	}
	printf("%lld\n",ans);
}

