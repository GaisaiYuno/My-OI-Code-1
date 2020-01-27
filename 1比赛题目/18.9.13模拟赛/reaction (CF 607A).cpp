#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#define maxn 100005 
using namespace std;
int n;
struct node{
	int a;
	int b;
	int last;
	node(){
		
	}
	node(int pos,int power){
		a=pos;
		b=power;
	}
	friend bool operator <(node x,node y){
		return x.a<y.a;
	}
}t[maxn]; 
int dp[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&t[i].a,&t[i].b);
	} 
	sort(t+1,t+1+n);
	for(int i=1;i<=n;i++){
		t[i].last=lower_bound(t+1,t+1+n,node(t[i].a-t[i].b,0))-t;
	}
	for(int i=1;i<=n;i++){
		if(t[i].last==0) dp[i]=i-1;
		else dp[i]=dp[t[i].last-1]+(i-t[i].last);
	}
	int ans=n;
	for(int end=n;end>=1;end--){
		ans=min(ans,dp[end]+(n-end));
	}
	printf("%d\n",ans);
}
