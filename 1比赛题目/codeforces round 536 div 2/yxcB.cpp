#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
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
int A[100005],B[100005];
struct node{
	int ind,val;
	friend bool operator <(node a,node b){
		if(a.val!=b.val) return a.val<b.val;
		return a.ind<b.ind;
	}
} s1[100005];
#undef int
int main(){
#define int long long
	int n,m;
	read(n),read(m);
	for(int i=1;i<=n;i++) read(A[i]);
	for(int i=1;i<=n;i++) read(B[i]),s1[i].ind=i,s1[i].val=B[i];
	sort(s1+1,s1+n+1);
	int i=0;
	while(m--){
		int a,b;
		read(a),read(b);
		if(b<=A[a]){
			A[a]-=b;
			printf("%I64d\n",b*B[a]);
			continue;
		}
		int ans=A[a]*B[a];
		b-=A[a];
		A[a]=0;
		while(b){
			if(A[s1[i].ind]==0) i++;
			if(i>n){
				puts("0");
				break;
			}
			if(b<=A[s1[i].ind]){
				A[s1[i].ind]-=b;
				printf("%I64d\n",ans+b*B[s1[i].ind]);
				break;
			}
			ans+=A[s1[i].ind]*B[s1[i].ind];
			b-=A[s1[i].ind];
			A[s1[i].ind]=0;
		}
	}
}

