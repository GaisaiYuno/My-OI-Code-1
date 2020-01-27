//For Selina 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100000
#define INF 0x3f3f3f3f3f3f3f3f
#define rg register
using namespace std;
typedef long long ll;
int n,m;
inline void qread(int& x){
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

namespace brute_force{
	vector<ll>a;
	int ans=0;
	ll val=INF;
	inline void debug(){
		for(int i=0;i<(int)a.size();i++) printf("%lld ",a[i]);
		printf("\n");
	} 
	inline void insert_head(int k){
		ans=1;
		val=0;
		for(rg int i=1;i<=k;i++) a.insert(a.begin(),0);
	}
	inline void insert_tail(int k){
		if(val>0){
			val=0;
			ans=a.size()+1;
		}
		for(rg int i=1;i<=k;i++) a.push_back(0);
	}
	inline void add(ll b,ll s){
		ans=0;
		val=INF;
		for(rg int i=0;i<(int)a.size();i++){
			a[i]+=b+s*i;
			if(a[i]<val){
				ans=i+1;
				val=a[i];
			}
		} 
//		for(rg vector<ll>::iterator it=a.begin();it!=a.end();it++){
//			(*it)+=b+s*(it-a.begin());
//			if((*it)<val){
//				ans=it-a.begin()+1;
//				val=(*it);
//			} 
//		}
	}
	void solve(){
		rg int cmd,k,b,s;
		insert_tail(n);
		for(rg int i=1;i<=m;i++){
			qread(cmd);
			if(cmd==1){
				qread(k);
				insert_head(k);
			}else if(cmd==2){
				qread(k);
				insert_tail(k);
			}else{
				qread(b);
				qread(s); 
				add(b,s);
			}
			qprint(ans);
			putchar(' ');
			qprint(val);
			putchar('\n');
		}
	} 
}

namespace no_op2{
	void solve(){
		int cmd,k,b,s;
		int ans;
		ll val=0; 
		for(int i=1;i<=m;i++){
			qread(cmd);
			if(cmd==1){
				qread(k);
				ans=1;
				val=0;
			}else if(cmd==2){
				
			}else{
				qread(b);
				qread(s); 
				ans=1;
				val+=b;
			}
			qprint(ans);
			putchar(' ');
			qprint(val);
			putchar('\n');
		}
	}
} 
int main(){
//	freopen("b.in","r",stdin); 
//	freopen("b.ans","w",stdout);
	qread(n);
	qread(m);
//	brute_force::solve();
	if(m<=5000||n==1) brute_force::solve();	
	else no_op2::solve();
} 
