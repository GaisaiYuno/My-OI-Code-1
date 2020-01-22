#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#define maxn 300005
#define ml 20
using namespace std;
void read(int &x){
	int f=1;x=0;
	char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}
struct _st{
	int st[maxn][ml+1];
	void init(int A[],int n){
		for(int i=1;i<=n;i++) st[i][0]=A[i];
		for(int i=n;i>=1;i--)
			for(int j=1;j<=ml&&i+(1<<(j-1))<=n;j++)
				st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	int query(int left,int right){
		if(left>right) return 0;
		int k=log2(right-left+1);
		return max(st[left][k],st[right-(1<<k)+1][k]);
	}
} st;
int A[maxn];
int erfen(int ind,int left,int right){
	left--,right++;
	while(left<right-1){
		int mid=(left+right)/2;
		if(st.query(mid,ind-1)<A[ind]) right=mid;
		else left=mid;
	}
	return left;
}
int erfen2(int ind,int left,int right){
	left--,right++;
	while(left<right-1){
		int mid=(left+right)/2;
		if(st.query(ind+1,mid)<A[ind]) left=mid;
		else right=mid;
	}
	return right;
}
struct node{
	int l,r;
	node(){l=r=0;}
	node(int a,int b){l=a,r=b;}
} B[maxn];
int query(int a,int b){
	
}
int main(){
	int n,m,type;
	read(n),read(m),read(type);
	for(int i=1;i<=n;i++) read(A[i]);
	st.init(A,n);
	for(int i=1;i<=n;i++){
		B[i].l=erfen(i,1,i-1);
		B[i].r=erfen2(i,i+1,n);
	}
	while(m--){
		int a,b;
		read(a),read(b);
		
	}
}
/*
10
3 6 8 14 6 8 4 7 1 2
*/
