//看了题解发现自己想复杂了
//对于一条边(u,v) 
//如果u>v则标红，否则标蓝。否则标蓝。
//因为从起点走过一个环回到起点的过程中，经过的点序号不可能始终单增或者单降，所以环边不会全部同色。 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector> 
#include<queue>
#define maxn 5000
using namespace std;
int n,m; 
vector<int>ans;
vector<int>E[maxn+5]; 
int in[maxn+5];
bool topo_sort(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(!in[i]) q.push(i);
	}
	int cnt=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cnt++;
		for(int y : E[x]){
			in[y]--;
			if(in[y]==0) q.push(y);
		}
	}
	if(cnt==n) return 1;
	else return 0;
}
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v); 
		if(u<v){
			ans.push_back(1);
		}else{
			ans.push_back(2);
		} 
		E[u].push_back(v);
		in[v]++;
	}
	if(topo_sort()){//无环 
		printf("1\n");
		for(int i=1;i<=m;i++) printf("1 ");
	}else{
		printf("2\n");
		for(int x : ans) printf("%d ",x); 
	}
}

