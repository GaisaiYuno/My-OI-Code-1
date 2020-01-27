#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 100005
using namespace std;
int A[maxn];
struct node{
	int s,d,ind,ans;
	node(){s=d=ind=ans=0;}
	node(int a,int b,int c){s=a,d=b,ind=c;ans=0;}
} B[maxn];
bool cmp1(node a,node b){return a.s>b.s;}
bool cmp2(node a,node b){return a.ind<b.ind;}
struct yxc{int val,ind;} C[maxn];
bool cmp3(yxc a,yxc b){return a.val>b.val;}
struct bcj{
	int A[maxn];
	int siz[maxn];
	bcj(){
		for(int i=1;i<=maxn;i++) A[i]=i,siz[i]=0;
	}
	int query(int x){
		if(x==A[x]) return x;
		A[x]=query(A[x]);
		return A[x];
	}
	void update(int x,int y){
		x=query(x),y=query(y);
		if(siz[x]>siz[y]) swap(x,y);
		A[x]=y;
		siz[y]+=siz[x];
	}
	int qsize(int x){
		return siz[query(x)];
	}
	void addsiz(int x){
		siz[query(x)]++;
	}
} V;
bool done[maxn];
int main(){
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	int n,b;
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	for(int i=1;i<=b;i++){
		scanf("%d%d",&B[i].s,&B[i].d);
		B[i].ind=i;
	}
	sort(B+1,B+b+1,cmp1);
	for(int i=1;i<=n;i++) C[i].val=A[i],C[i].ind=i;
	sort(C+1,C+n+1,cmp3);
	int ans=1;
	int cnt=1;
	for(int i=1;i<=b;i++){
		while(C[cnt].val>B[i].s){
			done[C[cnt].ind]=true;
			V.addsiz(C[cnt].ind);
			if(done[C[cnt].ind-1]) V.update(C[cnt].ind-1,C[cnt].ind);
			if(done[C[cnt].ind+1]) V.update(C[cnt].ind+1,C[cnt].ind);
			ans=max(ans,V.qsize(C[cnt].ind)+1);
			cnt++;
		}
		B[i].ans=(B[i].d>=ans);
	}
	sort(B+1,B+b+1,cmp2);
	for(int i=1;i<=b;i++) printf("%d\n",B[i].ans);
}
/*
8 7
0 3 8 5 6 9 0 0
0 5
0 6
6 2
8 1
10 1
5 3
150 7
*/
