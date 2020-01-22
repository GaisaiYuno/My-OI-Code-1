#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define maxn 300005
using namespace std;
struct node{
	int len;
	int beu;
	friend bool operator < (node p,node q){
		return p.beu>q.beu;
	}
}a[maxn];
priority_queue<int,vector<int>,greater<int> >h;
int n,k;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].len,&a[i].beu);
	}
	sort(a+1,a+1+n);
	long long sum=0,ans=0; 
	for(int i=1;i<=n;i++){
		h.push(a[i].len);
		sum+=a[i].len; 
		while(h.size()>k){
			sum-=h.top();
			h.pop();
		}
		ans=max(ans,sum*a[i].beu);
	}
	printf("%I64d\n",ans);
}

