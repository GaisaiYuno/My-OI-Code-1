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
ll b[maxn+5],c[maxn+5],d[maxn+5],e[maxn+5],sume[maxn+5];
ll maxc,minc;
inline ll calc(rg int i){
	rg ll ans=b[i]-d[i]*e[i]+sume[i];
	if(ans>maxc) maxc=ans;
	if(ans<minc) minc=ans;
	return ans;
}

inline void pre_work(){
	maxc=0;
	minc=INF;
	for(rg int i=1;i<=n;i++){
		e[i]=b[i]/d[i];
	}
	for(int i=1;i<=n;i++){
		sume[i]+=e[i];
		sume[i]+=e[a[i]];
		sume[a[i]]+=e[i];
	}
	for(rg int i=1;i<=n;i++){
		c[i]=calc(i); 
	}
}

inline void change(rg int x,rg int y){
	rg int z=a[x];
	d[z]--;
	d[y]++;
	
	sume[z]-=e[x];
	sume[z]-=e[z];
	e[z]=b[z]/d[z];
	sume[z]+=e[z];
	
	sume[y]-=e[y];
	e[y]=b[y]/d[y];
	sume[y]+=e[y];
	sume[y]+=e[x];
	
	c[x]=calc(x);
	c[y]=calc(y);
	c[z]=calc(z);
	
}

void debug(){
	printf("d: ");
	for(int i=1;i<=n;i++) printf("%lld ",d[i]);
	printf("\n");
	printf("e: ");
	for(int i=1;i<=n;i++) printf("%lld ",e[i]);
	printf("\n");
	printf("sume: ");
	for(int i=1;i<=n;i++) printf("%lld ",sume[i]);
	printf("\n");
}

int main(){
	int cmd,x,y;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(b[i]);
	}	
	for(int i=1;i<=n;i++){
		qread(a[i]);
		d[i]++;
		d[a[i]]++;
	}
	for(int i=1;i<=n;i++) d[i]++;
	pre_work();
#ifdef DEBUG
	debug();
#endif
	for(rg int i=1;i<=m;i++){
		qread(cmd);
		if(cmd==1){
			qread(x);
			qread(y);
			change(x,y);
#ifdef DEBUG
		debug();
#endif
		}else if(cmd==2){
			qread(x);
			qprint(c[x]);
			putchar('\n');
		}else{
			qprint(minc);
			putchar(' ');
			qprint(maxc);
			putchar('\n');
		}
	}
}
