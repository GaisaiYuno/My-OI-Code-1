#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 200005
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
inline void qread(long long &x){
	x=0;
	long long sign=1;
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
inline void qprint(int x){
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

int n,m,mv;
struct BIT{ 
	inline int lowbit(int x){
		return x&(-x);
	}
	int tree[maxn];
	void update(int x,int v){
		for(int i=x;i<=mv;i+=lowbit(i)){
			tree[i]+=v;
		}
	}
	int sum(int x){
		int ans=0;
		for(int i=x;i>0;i-=lowbit(i)){
			ans+=tree[i];
		}
		return ans;
	} 
	int query(int l,int r){
		return sum(r)-sum(l-1);
	}
}T; 
int pcnt;
int bcnt,bsz;
int a[maxn];
int tmp[maxn]; 
int b[maxn];
int id[maxn];
inline int lb(int id) {
	return bsz*(id-1)+1;
}
inline int rb(int id) {
	return min(bsz*id,n);
}

void discrete(){
	for(int i=1;i<=n;i++){
		tmp[i]=a[i];
	}
	sort(tmp+1,tmp+1+n);
	mv=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(tmp+1,tmp+1+mv,a[i])-tmp;
	}
}

int count_pair(){
	int ans=0;
	for(int i=n;i>=1;i--){
		ans+=T.sum(a[i]-1);
		T.update(a[i],1);
	}
	return ans;
}

void init_block(){
	bsz=sqrt(n);
	bcnt=1;
	for(int i=1; i<=n; i++) {
		b[i]=a[i];
		id[i]=bcnt;
		if(i%bsz==0) bcnt++;
	}
	for(int i=1; i<=bcnt; i++) {
		sort(b+lb(i),b+rb(i)+1);
	}
}

int query_small(int l,int r,int v) {
	int ans=0;
	for(int i=l; i<=min(r,rb(id[l])); i++) {
		if(a[i]<v) ans++;
	}
	for(int i=id[l]+1; i<id[r]; i++) {
		ans+=lower_bound(b+lb(i),b+rb(i)+1,v)-lb(i)-b;
	}
	if(id[l]!=id[r]) {
		for(int i=lb(id[r]); i<=r; i++) {
			if(a[i]<v) ans++;
		}
	}
	return ans;
}

int query_large(int l,int r,int v) {
	int ans=0;
	for(int i=l; i<=min(r,rb(id[l])); i++) {
		if(a[i]>v) ans++;
	}
	for(int i=id[l]+1; i<id[r]; i++) {
		ans+=(rb(i)-lb(i)+1)-(upper_bound(b+lb(i),b+rb(i)+1,v)-lb(i)-b)+1;
	}
	if(id[l]!=id[r]) {
		for(int i=lb(id[r]); i<=r; i++) {
			if(a[i]>v) ans++;
		}
	}
	return ans;
}

int query_ans(int l,int r){
	if(l+1<=r-1){
		pcnt+=query_large(l+1,r-1,a[l]);
		pcnt-=query_small(l+1,r-1,a[l]);
		pcnt-=query_large(l+1,r-1,a[r]);
		pcnt+=query_small(l+1,r-1,a[r]); 
	}
	if(a[l]<a[r]) pcnt++;
	if(a[l]>a[r]) pcnt--;
	return pcnt;
}

void update(int l,int r){
	swap(a[l],a[r]);
	for(int i=lb(id[l]);i<=rb(id[l]);i++) b[i]=a[i];
	sort(b+lb(id[l]),b+rb(id[l])+1);
	if(id[l]!=id[r]){
		for(int i=lb(id[r]);i<=rb(id[r]);i++) b[i]=a[i];
		sort(b+lb(id[r]),b+rb(id[r])+1);
	}
}
int main(){
	int l,r;
	qread(n);
	for(int i=1;i<=n;i++){
		qread(a[i]);
	}
	discrete();
	pcnt=count_pair();
	init_block();
	qprint(pcnt);
	putchar('\n');
	qread(m);
	for(int i=1;i<=m;i++){
		qread(l);
		qread(r);
		if(l>r) swap(l,r);
		qprint(query_ans(l,r));
		putchar('\n');
		update(l,r);
	}
}
