//http://119.29.55.79/problem/312
//把环复制，断环成链
//如果选择了某个区间[l,r]，下一个区间一定是与区间[l,r]相交的区间中，右端点最靠后的那一个。
//然后倍增找出第i个区间走2^j个区间后，到达第几个区间 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<cmath>
#define maxn 200000
#define maxlogn 21
using namespace std;
int n,m;
struct node{
	int l;
	int r;
	int id;
	node(){
		
	}
	node(int L,int R,int i){
		l=L;
		r=R;
		id=i;
	}
	friend bool operator < (node p,node q){
		if(p.l==q.l) return p.r<q.r;
		else return p.l<q.l;
	} 
}a[maxn*2+5]; 
int nex[maxn*2+5][maxlogn+5];
int ans[maxn*2+5];
int sz;
int main(){
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		if(x<y){
			a[++sz]=node(x,y,i);
			a[++sz]=node(x+m,y+m,i);
		}else{
			a[++sz]=node(x,y+m,i);
			a[++sz]=node(x+m,m*2,i);
		}
	}
	sort(a+1,a+1+sz);
	int l=1;
	for(int i=1;i<=sz;i++){
		//因为区间不互相包含，按l排序后，若l1<l2,则r1一定<r2，否则会被包含
		//所以只要找到最后一个 
		while(l<sz&&a[l+1].l<=a[i].r) l++;
		nex[i][0]=l;
	}
	int log2n=log2(2*n);
	for(int j=1;j<=log2n;j++){
		for(int i=1;i<=sz;i++){
			nex[i][j]=nex[nex[i][j-1]][j-1];
		}
	} 
	for(int i=1;i<=n;i++){
		int x=i,sum=1;
		for(int j=log2n;j>=0;j--){
			if(nex[x][j]-i<n){//由于数据保证一定有解，那n个区间一定能覆盖全部 
				sum+=(1<<j);
				x=nex[x][j];
			}
		}	
		ans[a[i].id]=sum;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}

