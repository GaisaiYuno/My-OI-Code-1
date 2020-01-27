#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#include<queue>
#define maxn 200000
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int a[maxn+5],b[maxn+5],c[maxn+5];
struct item{
	int id;
	int val;
	item(){
		
	}
	item(int _val,int _id){
		val=_val;
		id=_id;
	} 
	friend bool operator < (item p,item q){
		return p.val<q.val;
	}
}house[maxn+5];
 

priority_queue<int>q;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&b[i],&c[i]);
		house[i]=item(b[i],i);
	}
	sort(a+1,a+1+n);
	sort(house+1,house+1+m);
	long long ans=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<=m&&house[j].val<a[i]){
			q.push(c[house[j].id]-b[house[j].id]);
			j++;
		}
		if(!q.empty()){
			ans+=a[i]+q.top();
			q.pop();
			q.push(-a[i]);//相当于退流 
		}
	
	}
	printf("%lld\n",ans);
}
