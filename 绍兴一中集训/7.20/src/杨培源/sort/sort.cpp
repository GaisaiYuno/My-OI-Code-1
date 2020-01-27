#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define maxn 300000
using namespace std;
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
inline void qprint(long long x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
int dv;
int a[maxn+5];
int b[maxn+5];
void discrete(){
	for(int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+1+n);
	dv=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+1+dv,a[i])-b;
	}
}
namespace brute_force{
	
	int cnt;
	struct fenwick_tree{
		long long c[maxn+5];
		inline int lowbit(int x){
			return x&(-x);
		}
		void add(int x,int v){
			for(int i=x;i<=dv;i+=lowbit(i)) c[i]+=v;
			
		}
		long long sum(int x){
			long long ans=0;
			for(int i=x;i>0;i-=lowbit(i)) ans+=c[i];
			return ans;
		}
		long long query(int l,int r){
			return sum(r)-sum(l-1);
		}
	}T;
	
	int pos[maxn+5];
	int val[maxn+5];
	
	long long get_inv(){
		for(int i=1;i<=dv;i++) T.c[i]=0;
		long long ans=0;
		for(int i=n;i>=1;i--){
			ans+=T.sum(a[i]-1);
			T.add(a[i],1);
		}	
		return ans;
	}
	void change(int k){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]<=a[k]){
				pos[++cnt]=i;
				val[cnt]=a[i];
			}
		}
		sort(val+1,val+1+cnt);
		for(int i=1;i<=cnt;i++){
			a[pos[i]]=val[i];
		}
	}
	void solve(){
		int k;
		qprint(get_inv());
		putchar('\n');
		for(int i=1;i<=m;i++){
			qread(k);
			change(k);
			qprint(get_inv());
			putchar('\n');
		}
	}
}

namespace sol{
	struct node{
		int val;
		int pos;
		node(){
			
		}
		node(int _val,int _pos){
			val=_val;
			pos=_pos;
		}
		friend bool operator < (node p,node q){
			if(p.val==q.val) return p.pos<q.pos;
			return p.val<q.val;
		}
	};
	set<node>s;
	
	struct fenwick_tree{
		long long c[maxn+5];
		inline int lowbit(int x){
			return x&(-x);
		}
		void add(int x,int v){
			for(int i=x;i<=dv;i+=lowbit(i)) c[i]+=v;
			
		}
		long long sum(int x){
			long long ans=0;
			for(int i=x;i>0;i-=lowbit(i)) ans+=c[i];
			return ans;
		}
		long long query(int l,int r){
			return sum(r)-sum(l-1);
		}
	}T;
	
	//考虑值为v的数的逆序对，显然逆序对(v,x)满足x<v,排序后x到了v前面，逆序对全部没了 
	//记录一下值v对应的逆序对数 
	//查询a[k]的时候，把答案减去1，2，3...a[k]对应的逆序对数
	//前缀和优化一下即可 
	long long pr[maxn+5];
	long long sumpr[maxn+5]; 
	
	int mark[maxn+5];
	void solve(){
		int k;
		for(int i=n;i>=1;i--){
			pr[a[i]]+=T.sum(a[i]-1);//在洛谷 
			T.add(a[i],1);
		}
		for(int i=1;i<=dv;i++){
			sumpr[i]=sumpr[i-1]+pr[i];
		}
		for(int i=1;i<=n;i++){
			s.insert(node(a[i],i));
		}
		
		qprint(sumpr[dv]);
		putchar('\n');
		int maxa=0;
		for(int i=1;i<=m;i++){
			qread(k);
			if(!mark[a[k]]){
				maxa=max(maxa,a[k]);
				set<node>::iterator it=s.lower_bound(node(a[k],0));
				while(!mark[it->val]){
					mark[it->val]=1;
					if(it==s.begin()) break;
					else it--;
				}
			}
			qprint(sumpr[dv]-sumpr[maxa]);
			putchar('\n');
		} 
	}
}
int main(){
//	freopen("sort.in","r",stdin);
//	freopen("sort.out","w",stdout);
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++) qread(a[i]);
	discrete();
//	brute_force::solve();	
	sol::solve();
}
