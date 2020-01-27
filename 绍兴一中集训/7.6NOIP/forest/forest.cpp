#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define rg register
#define maxn 300000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
inline void qread(int &x){
	x=0;
	rg int sign=1;
	rg char c=getchar();
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
inline void qread(ll &x){
	x=0;
	rg int sign=1;
	rg char c=getchar();
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
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}
}
inline void qprint(ll x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}
}


int n,m;
int a[maxn];
ll b[maxn+5],c[maxn+5],d[maxn+5],e[maxn+5];
ll maxc,minc;

namespace bf1{
	inline ll calc(rg int x){
		for(int i=1;i<=n;i++){
			e[i]=b[i]/d[i];
		}
		int sume=0;
		for(rg int i=1;i<=n;i++){
			if(a[i]==x) sume+=e[i];
			if(i==x) sume+=e[i];
		}
		sume+=e[a[x]];
		c[x]=b[x]-d[x]*e[x]+sume;
		if(c[x]>maxc) maxc=c[x];
		if(c[x]<minc) minc=c[x];
		return c[x];
	}

	inline void change(rg int x,rg int y){
		rg int z=a[x];
		d[z]--;
		d[y]++;
		a[x]=y;
	}

	void solve(){
		int cmd,x,y;
		for(int i=1;i<=n;i++){
			qread(b[i]);
		}	
		for(int i=1;i<=n;i++){
			qread(a[i]);
			d[i]++;
			d[a[i]]++;
		}
		for(int i=1;i<=n;i++) d[i]++;
		maxc=0;
		minc=INF;
		for(rg int i=1;i<=m;i++){
			qread(cmd);
			if(cmd==1){
				qread(x);
				qread(y);
				change(x,y);
			}else if(cmd==2){
				qread(x);
				qprint(calc(x));
				putchar('\n');
			}else{
				qprint(minc);
				putchar(' ');
				qprint(maxc);
				putchar('\n');
			}
		}
	}
}

namespace bf2{
	
		vector<int>link[maxn+5];
	inline ll calc(rg int x){
		e[x]=b[x]/d[x];
		rg ll sume=e[x];
		rg int sz=link[x].size();
		for(rg int i=0;i<sz;i++){
			int y=link[x][i];
			e[y]=b[y]/d[y];
			sume+=e[y];
		}
		c[x]=b[x]-d[x]*e[x]+sume;
		if(c[x]>maxc) maxc=c[x];
		if(c[x]<minc) minc=c[x];
		return c[x];
	}
	
	inline void insert(vector<int> &v,int x){
		v.push_back(x);
	}

	inline void del(vector<int> &v ,int x){
	//#ifdef DEBUG
	//	print(v);
	//#endif
//		printf("%d ",*v.begin());
		vector<int>::iterator del;
		for(vector<int>::iterator it=v.begin();it!=v.end();it++){
			if(*it==x) del=it;
		}
		v.erase(del);
	//	int it=lower_bound(v.begin(),v.end(),x)-v.begin();
	//	printf("db %d:\n",it);
	//	v.erase(it);
	}
	
	inline void change(rg int x,rg int y){
	
		rg int z=a[x];
		del(link[x],z);
		del(link[z],x);
		insert(link[x],y);
		insert(link[y],x);
		d[z]--;
		d[y]++;
		a[x]=y;
	}
	
	//void debug(){
	//	printf("d: ");
	//	for(int i=1;i<=n;i++) printf("%lld ",d[i]);
	//	printf("\n");
	//	printf("e: ");
	//	for(int i=1;i<=n;i++) printf("%lld ",e[i]);
	//	printf("\n");
	//	printf("sume: ");
	//	for(int i=1;i<=n;i++) printf("%lld ",sume[i]);
	//	printf("\n");
	//}
	
	void solve(){
		int cmd,x,y;
		for(int i=1;i<=n;i++){
			qread(b[i]);
		}	
		for(int i=1;i<=n;i++){
			qread(a[i]);
			d[i]++;
			d[a[i]]++;
			link[a[i]].push_back(i);
			link[i].push_back(a[i]);
		}
		for(int i=1;i<=n;i++) d[i]++;
		maxc=0;
		minc=INF;
		for(rg int i=1;i<=m;i++){
			qread(cmd);
			if(cmd==1){
				qread(x);
				qread(y);
				change(x,y);
			}else if(cmd==2){
				qread(x);
				qprint(calc(x));
				putchar('\n');
			}else{
				qprint(minc);
				putchar(' ');
				qprint(maxc);
				putchar('\n');
			}
		}
	}
}

int main(){
#ifndef LOCAL
	freopen("forest.in","r",stdin);
	freopen("forest.out","w",stdout);
#endif
	qread(n);
	qread(m);
	if(n<3000) bf1::solve();
	else bf2::solve();
}

