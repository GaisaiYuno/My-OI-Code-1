#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxans 1e18 
using namespace std;
typedef long double ll;
int cas,n,L,P;
char str[maxn+5];
int sum[maxn+5];
inline ll abs(ll x){
	return x>=0?x:-x;
}
inline ll fast_pow(ll x,int k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}

struct node{
	int l;
	int r;
	int pos;
	node(){
		
	}
	node(int L,int R,int p){
		l=L;
		r=R;
		pos=p;
	}
}q[maxn+5];
int head,tail;
ll dp[maxn+5];
inline ll get_val(int j,int i){
	return dp[j]+fast_pow(abs(sum[i]-sum[j]+(i-j-1)-L),P);
}

int bin_search(int i,int j,int l,int r){
	int ans=0;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(get_val(i,mid)<=get_val(j,mid)){
			ans=mid;
			l=mid+1;
		}
	}
	return ans+1;
}
ll solve(){
	head=tail=1;
	q[head]=node(0,n,0);
	for(int i=1;i<=n;i++){
		while(head<=tail){
			if(q[head].r<=i-1) head++;
			else{
				q[head].l=i;
				break;
			}
		}
		
		dp[i]=get_val(q[i].pos,i);
		
		int pos=-1;
		while(head<=tail){
			if(get_val(i,q[tail].l)<=get_val(q[tail].pos,q[tail].l)){
				pos=q[tail].l;
				tail--;
			}else{
				if(get_val(q[tail].pos,q[tail].r)<=get_val(i,q[tail].r)) break;
				else{
					pos=bin_search(i,q[head].pos,q[head].l,q[head].r);
					break;
				}
			}
		}
		if(pos!=-1){
			q[++head]=node(pos,n,i);
		}
	}
	return dp[n];
}
int main(){
	scanf("%d",&cas);
	while(cas--){
		scanf("%d %d %d",&n,&L,&P);
		for(int i=1;i<=n;i++){
			scanf("%s",str+1);
			sum[i]=sum[i-1]+strlen(str+1);
		}
		ll ans=solve();
		if(ans> maxans) printf("Too hard to arrange");
		else{
			long long tmp=ans;
			printf("%lld\n",tmp);
		}
	}

}

