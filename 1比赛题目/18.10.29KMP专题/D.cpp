#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100005
using namespace std;
int n,m,s;
struct BIT{
	int sum[30];
	inline int lowbit(int x){
		return x&(-x);
	}
	void clear(){
		memset(sum,0,sizeof(sum));
	}
	void update(int x,int v){
		while(x<=s){
			sum[x]+=v;
			x+=lowbit(x);
		}
	}
	int query(int x){
		int ans=0;
		while(x){
			ans+=sum[x];
			x-=lowbit(x);
		}
		return ans;
	}
}T;
int a[maxn];
int b[maxn];
int p1[maxn];
int p2[maxn];
int next[maxn];
vector<int>ans;
void kmp(){
	T.clear();
	for(int i=1;i<=m;i++){
		p1[i]=T.query(b[i]-1);
		p2[i]=T.query(b[i]);
		T.update(b[i],1);
	}
	T.clear();
	next[1]=0;
	for(int i=2,j=0;i<=m;i++){
		while(j>0&&(T.query(b[i]-1)!=p1[j+1]||T.query(b[i])!=p2[j+1])){
			for(int k=i-j;k<i-next[j];k++) T.update(b[k],-1);
			j=next[j];
		}
		if(T.query(b[i]-1)==p1[j+1]&&T.query(b[i])==p2[j+1]) j++;
		next[i]=j;
		T.update(b[i],1);
	}
//	for(int i=1;i<=n;i++){
//    	printf("%d ",next[i]);
//	}
//	printf("\n");
	T.clear();
	for(int i=1,j=0;i<=n;i++){
		while(j==m||(j>0&&(T.query(a[i]-1)!=p1[j+1]||T.query(a[i])!=p2[j+1]))){
			for(int k=i-j;k<i-next[j];k++) T.update(a[k],-1);
			j=next[j];
		}
		if(T.query(a[i]-1)==p1[j+1]&&T.query(a[i])==p2[j+1]) j++;
		if(j==m) ans.push_back(i-m+1);
		T.update(a[i],1);
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	kmp();
	int t=ans.size();
	printf("%d\n",t);
	for(int i=0;i<t;i++){
		printf("%d\n",ans[i]);
	}
}
