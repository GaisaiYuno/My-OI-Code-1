#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
#define maxn 1000000
using namespace std;
namespace IO{
	int c;
	unsigned int seed;
	unsigned int randnum(){
		seed^=seed<<13;
		seed^=seed>>17;
		seed^=seed<<5;
		return seed;
	}

	inline int read(int &x){scanf("%d",&x);return x;}
	inline void init_case(int &m,int &a,int &b,int &d,int p[]){
		scanf("%d%u%d%d%d%d",&m,&seed,&a,&b,&c,&d);
		for(int i=1;i<=m;i++){
			if(randnum()%c==0)p[i]=-1;
			else p[i]=randnum()%b;
		}
	}

	inline void update_ans(unsigned int &ans_sum,unsigned int cur_ans,int no){
		const static unsigned int mod=998244353;
		ans_sum^=(long long)no*(no+7)%mod*cur_ans%mod;
	}
}
using IO::read;
using IO::init_case;
using IO::update_ans;
int p[2000005];
int m,a,b,d;

namespace brute_force{
	struct segment_tree{
		struct node{
			int l;
			int r;
			int sum;
			int mex;
		}tree[maxn*4+5];
		void push_up(int pos){
			tree[pos].sum=tree[pos<<1].sum+tree[pos<<1|1].sum;
			tree[pos].mex=min(tree[pos<<1].mex,tree[pos<<1|1].mex); 
		}
		void build(int l,int r,int pos){
			tree[pos].l=l;
			tree[pos].r=r;
			if(l==r){
				tree[pos].sum=0;
				tree[pos].mex=l;
				return;
			}
			int mid=(l+r)>>1;
			build(l,mid,pos<<1);
			build(mid+1,r,pos<<1|1);
			push_up(pos);
		}
		void update(int tpos,int val,int pos){
			if(tree[pos].l==tree[pos].r){
				tree[pos].sum=val;
				if(val==0) tree[pos].mex=tree[pos].l;
				else tree[pos].mex=b+1;
				return;
			}
			int mid=(tree[pos].l+tree[pos].r)>>1;
			if(tpos<=mid) update(tpos,val,pos<<1);
			else update(tpos,val,pos<<1|1);
			push_up(pos);
		}
		int find(int tpos,int pos){
			if(tree[pos].l==tree[pos].r){
				return tree[pos].sum;
			}
			int mid=(tree[pos].l+tree[pos].r)>>1;
			if(tpos<=mid) return find(tpos,pos<<1);
			else return find(tpos,pos<<1|1);
		}
		int query(int L,int R,int pos){
			if(L<=tree[pos].l&&R>=tree[pos].r){
				return tree[pos].mex;
			}
			int mid=(tree[pos].l+tree[pos].r);
			int ans=b+1;
			if(L<=mid) ans=min(ans,query(L,R,pos<<1));
			if(R>mid) ans=min(ans,query(L,R,pos<<1|1));
			return ans;
		}
	}Tr;
	
	struct num{
		int val;
		int tim;
		num(){
			
		}
		num(int _val,int _tim){
			val=_val;
			tim=_tim;
		}
		friend bool operator < (num x,num y){
			if(x.tim==y.tim) return x.val<y.val;
			return x.tim>y.tim;
		}
	};
	set<num>S;//记录被删除的数字 
	int tim[maxn+5];
	int is_insert[maxn+5];
	int in_set[maxn+5];
	
	int insert_new(int val){
		is_insert[val]=1;
		in_set[val]=1;
		if(tim[val]==0){//之前没有被删除过，不在s集合里  
			Tr.update(val,1,1);
		}else{
			set<num>::iterator it=S.lower_bound(num(val,tim[val]));
			if(it!=S.end()) S.erase(it);
			tim[val]=0;
			Tr.update(val,1,1);
		} 
		return Tr.query(0,b,1);
	}
	
	int del(int val,int t){
		tim[val]=t;
		S.insert(num(val,tim[val]));
		in_set[val]=0;
		Tr.update(val,0,1);
		return Tr.query(0,b,1);
	}
	
	int insert_back(){
		if(S.empty()) return 0;//没有符合条件的数 
		set<num>::iterator it=S.begin();
		int val=it->val;
		S.erase(it);
		tim[val]=0;
		in_set[val]=1;
		Tr.update(val,1,1);
		return Tr.query(0,b,1);
	}
	
	unsigned int calc(int p,int t){
		if(p==-1){
			return insert_back(); 
		}else if(is_insert[p]==0){
			return insert_new(p);
		}else if(in_set[p]==1){
			return del(p,t);
		}else{
			return insert_back();
		}
	}
	void solve(){
		unsigned int ans_sum=0,cur_ans=0;
		for(int i=0;i<=b;i++){
			tim[i]=0;
			is_insert[i]=0;
			in_set[i]=0;
		}
		S.clear(); 
		Tr.build(0,b,1);
		for(int i=0;i<=a;i++){
			Tr.update(i,1,1);
			is_insert[i]=1;
			in_set[i]=1;
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
			cur_ans=calc(p[i],i);
			update_ans(ans_sum,cur_ans,i);
			printf("Q=%d A=%u\n",p[i],cur_ans);
		}
		printf("%u\n",ans_sum);
	}
}

//namespace d_1{
//	int is_insert[maxn+5];
//	int is_inset[maxn+5]; 
//	void solve(){
//		unsigned int ans_sum=0,cur_ans=0;
//		int mex=a+1;
//		for(int i=1;i<=a;i++){
//			is_insert[i]=1;
//			is_inset[i]=1;
//		}
//		for(int i=1;i<=m;i++){
//			if(p[i]==-1){
//				continue;
//			}else if(is_insert[p[i]]==0){
//				is_insert[p[i]]=is_inset[p[i]]=1;
//				if(p[i]>mex){
//					cur_ans=mex;
//				}else if(p[i]==mex){
//					
//				}else{
//					
//				}
//			}else if(is_inset[p[i]]){
//				continue;
//			}else{
//				continue;
//			}
//		}
//	}
//}

int main(){
	int T;
#ifndef LOCAL
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
#endif
	read(T);
	
	while(T--){
		scanf("%d %d %d",&m,&a,&b);

		brute_force::solve();		
	}
	return 0;
}
