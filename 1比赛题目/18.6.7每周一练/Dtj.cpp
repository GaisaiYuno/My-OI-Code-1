#include<stdio.h>
#include<iostream>
#include<string.h>
#include<set>
#include<vector>
#include<map>
#include<math.h>
#include<queue>
#include<string>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define N 500005
#define ll int
ll n;
ll c[N], maxn;
inline ll lowbit(ll x){return x&(-x);}
void change(ll pos, ll val){
	while(pos)c[pos]=max(c[pos],val), pos-=lowbit(pos);
}
ll maxx(ll pos){
	ll ans = -1;
	while(pos<=maxn)ans = max(ans,c[pos]),pos+=lowbit(pos);
	return ans;
}
struct node{
	ll b[3],num;
}w[N];
bool cmp0(node x, node y){return x.b[0]<y.b[0];}
bool cmp1(node x, node y){return x.b[1]>y.b[1];}
int main(){
	ll i,j;
	while(cin>>n) {
		for(i=0;i<n;i++)scanf("%d",&w[i].b[0]);
		for(i=0;i<n;i++)scanf("%d",&w[i].b[1]);
		for(i=0;i<n;i++)scanf("%d",&w[i].b[2]);
		sort(w, w+n, cmp0);
		ll rank = 1;
		w[0].num = 1;
		for(i=1;i<n;i++) {
			if(w[i].b[0]==w[i-1].b[0])w[i].num = rank;
			else w[i].num = ++rank;
		}
		sort(w,w+n,cmp1);
		for(i=1;i<=rank;i++)c[i]=-1;
		maxn = rank;
		i = 0;
		ll ans = 0;
		while(i<n) {
			for(j = i; j < n && w[i].b[1] == w[j].b[1]; j++)
				if(maxx(w[j].num+1)>w[j].b[2])
					ans++;
			for(j = i; j < n && w[i].b[1] == w[j].b[1]; j++)
				change(w[j].num, w[j].b[2]);
			i = j;
		}
		cout<<ans<<endl;
	}
	return 0;
}
