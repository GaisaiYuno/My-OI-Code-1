#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<cmath>
#include<queue>
#define maxn 400000
#define maxb 1000
using namespace std;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
int a[maxn+5];

int bsz;
int bel[maxn+5];
inline int lb(int id){
	return bsz*(id-1)+1;
}
inline int rb(int id){
	return bsz*id>=n?n:bsz*id; 
}
priority_queue<int>num[maxb+5];//大根堆，存储每一块中的数 
priority_queue<int,vector<int>,greater<int> >mark[maxb+5] ;//小根堆，存储每一个块上替换标记 
//从小到大是因为序列中的数会被优先换成小的标记
void rebuild(int id){//重构每个块，不管是整块替换还是部分替换，都要调用rebuild 
	while(!num[id].empty()) num[id].pop();
	for(int i=lb(id);i<=rb(id);i++){
		num[id].push(a[i]);
	}
}
void push_down(int id){
	if(!mark[id].empty()){
		for(int i=lb(id);i<=rb(id);i++){
			int v=mark[id].top();
			if(v<a[i]){
				swap(a[i],v);
				mark[id].pop();
				mark[id].push(v);//把a[i]与v交换 
			}
		}
		while(!mark[id].empty()) mark[id].pop();
		rebuild(id); 
	}
	
} 

int update(int l,int r,int A){
	push_down(bel[l]);//非整块操作，必须下推标记 
	for(int i=l;i<=min(r,rb(bel[l]));i++){
		if(A<a[i]) swap(a[i],A);
	}
	rebuild(bel[l]);
	for(int i=bel[l]+1;i<bel[r];i++){
		int v=num[i].top();
		if(v>A){ //如果最大值比A小，就不替换了 
			num[i].pop();
			num[i].push(A);
			mark[i].push(A);
			swap(A,v);
			//整块修改的时候只需要替换最大值，剩下的操作push_down的时候完成
		}
	}
	if(bel[l]!=bel[r]){
		push_down(bel[r]);
		for(int i=lb(bel[r]);i<=r;i++){
			if(A<a[i]) swap(a[i],A);
		}
		rebuild(bel[r]);
	}
	return A;
}
int main(){
	int l,r,A;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++) qread(a[i]);
	bsz=sqrt(n);
	for(int i=1;i<=n;i++){
		bel[i]=(i-1)/bsz+1;
		num[bel[i]].push(a[i]); 
	}
	for(int i=1;i<=m;i++){
		qread(l);
		qread(r);
		qread(A);
		if(l<=r){
			A=update(l,r,A);
		}else{
			A=update(l,n,A);
			A=update(1,r,A);
		}
//		printf("db:"); 
		qprint(A);
		putchar('\n');
	} 
}

