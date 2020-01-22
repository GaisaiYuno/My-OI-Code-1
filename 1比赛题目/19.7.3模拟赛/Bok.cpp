#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 50000
using namespace std;
int n,m,bsz;
int a[maxn+5];
int blo[maxn+5];
struct node{
	int l;
	int r;
	int id;
	int sign;
	node(){
		
	}
	node(int _l,int _r,int _id,int _sign){
		if(_l>_r) swap(_l,_r);//因为输入的只是两个变量而不是区间，记得swap 
		l=_l;
		r=_r;
		id=_id;
		sign=_sign;
	}
	friend bool operator < (node p,node q){
		if(blo[p.l]==blo[q.l]) return p.r<q.r;
		else return blo[p.l]<blo[q.l];
	} 
}b[maxn*4+5];
long long ans[maxn+5];
long long sum=0;
int cnt=0;
int tmp1[maxn+5],tmp2[maxn+5];
int main(){
	int l1,r1,l2,r2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		b[++cnt]=node(r1,r2,i,1);
		b[++cnt]=node(l2-1,r1,i,-1);
		b[++cnt]=node(l1-1,r2,i,-1);
		b[++cnt]=node(l1-1,l2-1,i,1);
	}
	bsz=sqrt(n);
	for(int i=1;i<=n;i++){
		blo[i]=i/bsz+1;
	}
	sort(b+1,b+1+cnt);
	
	int l=0,r=0;
	for(int i=1;i<=cnt;i++){
		while(l<b[i].l){
			l++;
			sum+=tmp2[a[l]];
			tmp1[a[l]]++; 
		}
		while(r<b[i].r){
			r++;
			sum+=tmp1[a[r]];
			tmp2[a[r]]++;
		}
		while(l>b[i].l){
			sum-=tmp2[a[l]];
			tmp1[a[l]]--;
			l--;
		}
		while(r>b[i].r){
			sum-=tmp1[a[r]];
			tmp2[a[r]]--;
			r--;
		}
		ans[b[i].id]+=sum*b[i].sign;
	}
	for(int i=1;i<=m;i++){
		printf("%lld\n",ans[i]);
	}
}
