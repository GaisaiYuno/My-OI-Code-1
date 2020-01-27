//http://119.29.55.79/contest/98/problem/4
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<cmath>
#include<algorithm> 
#define INF 0x3f3f3f3f
#define maxn 2000000
#define maxlogn 25
using namespace std;
int n,len;
struct seg{
	int l;
	int r;
	int id;
	seg(){
		
	}
	seg(int _l,int _r,int _id){
		l=_l;
		r=_r;
		id=_id;
	}
	friend bool operator  < (seg p,seg q){
		if(p.l==q.l) return p.r<q.r;
		else return p.l<q.l;
	}
}a[maxn+5]; 
int sz;
int log2n; 
int ans[maxn+5];
int anc[maxn+5][maxlogn+5];

int query(int x){
	int ans=1;
	int r=a[x].l+len; //注意边界，比如3->5,5->1,1->3.必须要跳回原点3,所以是+len而不是+len-1 
	for(int i=log2n;i>=0;i--){
		if(anc[x][i]!=0&&a[anc[x][i]].r<=r){
			ans+=(1<<i); 
			x=anc[x][i];
		}
	}
	if(anc[x][0]&&a[x].r<r){
		ans++;
		x=anc[x][0];
	}
	return ans; 
}
int main(){
	int l,r;
	scanf("%d %d",&n,&len);
	log2n=log2(n*2);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&l,&r);
		if(l<=r){
			a[++sz]=seg(l,r,i);
			a[++sz]=seg(l+len,r+len,i+n);
		}else{
			a[++sz]=seg(l,r+len,i);
			a[++sz]=seg(l+len,r+len+len,i+n);
		}
	}
	sort(a+1,a+1+sz);
	int ptr=1;
	for(int i=1;i<=sz;i++){
		while(ptr<sz&&a[ptr+1].l<=a[i].r) ptr++;
		if(ptr!=i) anc[i][0]=ptr;
	}
	for(int j=1;j<=log2n;j++){
		for(int i=1;i<=sz;i++){
			anc[i][j]=anc[anc[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=sz;i++){
		if(a[i].id<=n) ans[a[i].id]=query(i);//注意要跳过(l+n,r+n)，否则l+len会超过2*len导致答案错误 
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}

