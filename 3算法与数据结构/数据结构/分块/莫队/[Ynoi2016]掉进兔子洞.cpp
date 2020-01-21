//https://www.luogu.org/problem/P4688
//答案为区间长度-每个数在三个区间中出现的最小次数*3
//考虑用bitset维护区间权值集合，相同的数看作不同的 
//and一下就得到最小次数 
//把询问的三个区间拆开解决，最后再合并 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>
#define maxn 100000
#define maxt 25000
using namespace std;
int n,m; 
int a[maxn+5];
int tmp[maxn+5];
void discrete(){
	//数字可能重复出现，bitset只能记录0和1，离散化前不能去重。
	//1 2 2 3 3 ->1 2 2 4 4
	//然后储存的时候用x+cnt[x]存储相同的数，如第1个2存储在3 
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	sort(tmp+1,tmp+1+n);
	for(int i=1;i<=n;i++) a[i]=lower_bound(tmp+1,tmp+1+n,a[i])-tmp; 
}
int bsz;
int belong[maxn+5];
struct que{
	int l;
	int r;
	int id;
	friend bool operator < (que p,que q){
		if(belong[p.l]==belong[q.l]) return p.r<q.r;
		else return belong[p.l]<belong[q.l];
	}
}q[maxn+5];
bitset<maxn+5>f;
bitset<maxn+5>res[maxt+5];
int cntv[maxn+5];
int len[maxt+5];
void add(int val){
	//第x个数，个数为cntv[x]的时候，bitset第[x+cntv[x]]位为1 
	f[val+cntv[val]]=1;
	cntv[val]++;
}
void del(int val){
	f[val+cntv[val]-1]=0;
	cntv[val]--;
}

void print(bitset<maxn+5> &x){
	for(int i=0;i<n;i++) cout<<x[i];
	printf("\n");
}
void solve(int x,int y){//分批处理 
	int l,r;
	int cnt=0;
	memset(cntv,0,sizeof(cntv));
	memset(len,0,sizeof(len));
	f.reset();
	for(int i=x;i<=y;i++){
		cnt++;
		scanf("%d %d",&q[cnt].l,&q[cnt].r);
		len[i-x+1]+=q[cnt].r-q[cnt].l+1;
		q[cnt].id=i-x+1;
		
		cnt++;
		scanf("%d %d",&q[cnt].l,&q[cnt].r);
		len[i-x+1]+=q[cnt].r-q[cnt].l+1;
		q[cnt].id=i-x+1;
		
		cnt++;
		scanf("%d %d",&q[cnt].l,&q[cnt].r);
		len[i-x+1]+=q[cnt].r-q[cnt].l+1;
		q[cnt].id=i-x+1;
		
		res[i-x+1].set();//把所有位初始值设成1，方便等下直接&,如果初始为0，&完还是0 
	}
	sort(q+1,q+1+cnt);
	l=1,r=0;
	for(int i=1;i<=cnt;i++){
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		//先add再del,避免删的数cnt为0造成的玄学错误 
		while(l<q[i].l) del(a[l++]);
		while(r>q[i].r) del(a[r--]);
		res[q[i].id]&=f; 
	}
	
	for(int i=1;i<=y-x+1;i++) printf("%d\n",len[i]-(int)res[i].count()*3);
} 
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	discrete();
	bsz=sqrt(n);
	for(int i=1;i<=n;i++) belong[i]=i/bsz+1;
	for(int i=1;i<=m;i+=maxt) solve(i,min(i+maxt-1,m)); 
}

