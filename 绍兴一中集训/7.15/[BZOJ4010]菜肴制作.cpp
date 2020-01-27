//https://www.luogu.org/problemnew/show/P3243
/*
看到题目，可以想到拓扑排序。但是如果要求字典序最小的排列，那就错了。
可以举出反例：44种菜肴，限制为<2,4><3,1>
那么字典序最小的是2,3,1,4但题目要求的最优解是3,1,2,4
继续考虑，可以发现，如果最后一个数字在合法范围内尽可能大，那么这样是绝对有利的。
因为如果设最后一个数字是xx，那么除了xx之外的所有数都不会被放到最后一个位置。
而这样就可以让前面所有小于xx的数都尽量靠前（大于xx的数，虽然也能靠前，但由于xx的位置已经固定，因此没有用），达到题目的目标。
因此，最优解就是符合条件的排列中，反序列的字典序最大的排列。

*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define maxn 100000 
using namespace std;
int t,n,m;
vector<int>E[maxn+5];
int in[maxn+5];
vector<int>seq;
priority_queue<int>q;
void ini(){
	for(int i=1;i<=n;i++){
		E[i].clear();
		in[i]=0;
	}
	seq.clear();
	while(!q.empty()) q.pop();
}
bool topo_sort(){
	for(int i=1;i<=n;i++){
		if(in[i]==0) q.push(i);
	}
	while(!q.empty()){
		int x=q.top();
		q.pop();
		seq.push_back(x);
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			in[y]--;
			if(in[y]==0) q.push(y);
		}
	}
	for(int i=1;i<=n;i++){
		if(in[i]!=0) return 0;
	}
	return 1;
}
int main(){
	int u,v;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		ini();
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			E[v].push_back(u);
			in[u]++;
		}
		if(topo_sort()){
			for(int i=n-1;i>=0;i--){
				printf("%d ",seq[i]);
			}
			printf("\n");
		}else{
			printf("Impossible!\n");
		}
	}
}
