//https://www.cnblogs.com/birchtree/p/10500287.html
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue> 
#define maxn 200005
using namespace std;
struct node{
	long long dtim;
	int id;
	node(){
		
	}
	node(int i,long long t){
		id=i;
		dtim=t;
	}
	friend bool operator < (node p,node q){
		return p.dtim>q.dtim;
	}
};
int n,k;
long long a[maxn],b[maxn];
long long num[maxn];
bool check(long long add){
	priority_queue<node>q;
	for(int i=1;i<=n;i++){
		q.push(node(i,a[i]/b[i]+1));
		num[i]=0;
	}
	for(int i=1;i<=k;i++){
		node now=q.top();
		q.pop();
		if(now.dtim<i) return 0;
		num[now.id]++;
		long long sum=a[now.id]+num[now.id]*add;
		q.push(node(now.id,sum/b[now.id]+1));
	}
	return 1;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%I64d",&b[i]);
	}
	long long l=0,r=1e13,ans=-1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1; 
	}
	printf("%I64d\n",ans);
}

