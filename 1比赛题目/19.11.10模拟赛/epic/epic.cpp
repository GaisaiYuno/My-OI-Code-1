#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>
#define maxn 100000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
int n,k;
ll a[maxn+5];
struct node{
	int deep;
	ll val;
	node(){
		
	}
	node(int _deep,ll _val){
		deep=_deep;
		val=_val;
	}
	friend bool operator < (node p,node q){
		if(p.val==q.val) return p.deep>q.deep;
		else return p.val>q.val;
	}
};
pair<ll,int> huffman(int cnt){
	priority_queue<node>q;
	ll sum=0;
	int maxl=0;
	for(int i=1;i<=n;i++) q.push(node(0,a[i]));
	for(int i=1;i<=cnt;i++) q.push(node(0,0));
	while(q.size()>1){
		node now=node(0,0);
		for(int i=1;i<=k;i++){
			node p=q.top();
			q.pop();
			now.val+=p.val;
			now.deep=max(now.deep,p.deep+1);
			if(q.empty()) break;
		}
		sum+=now.val;
		maxl=max(maxl,now.deep);
		q.push(now);
	}
	return make_pair(sum,maxl);
}
int main(){
//	freopen("epic.in","r",stdin);
//	freopen("epic.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int cnt0=0;
	if((n-1)%(k-1)!=0){
		cnt0=(k-1)-(n-1)%(k-1);
	}
	pair<ll,int>res=huffman(cnt0);
	printf("%lld\n%d\n",res.first,res.second);
	
}
