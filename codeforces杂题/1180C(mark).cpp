//在最大的数排到第1个之后就不会动了，然后后面的循环动 
#include<iostream>
#include<cstdio>
#include<utility>
#include<queue>
#define maxn 300000
using namespace std;
int n,m; 
int sz=0;
int a[maxn+5];
pair<int,int>ans[maxn+5];
deque<int>q;
int main(){
	scanf("%d %d",&n,&m);
	int maxv=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxv=max(maxv,a[i]); 
		q.push_back(a[i]);
	}
	while(1){
		int x=q.front(),y=*(++q.begin());
		ans[++sz]=make_pair(x,y);
		if(q.front()==maxv) break;
		else{
			q.pop_front();
			q.pop_front();
			if(x<=y) swap(x,y);
			q.push_front(x);
			q.push_back(y);
		}
	}
	int id=0;
	while(!q.empty()){
		a[++id]=q.front();
		q.pop_front(); 
	} 
	long long x;
	for(int i=1;i<=m;i++){
		scanf("%I64d",&x);
		if(x<=sz){
			printf("%d %d\n",ans[x].first,ans[x].second);
		}else{
			printf("%d %d\n",maxv,a[(x-sz)%(n-1)+2]);
		}
	}
}

