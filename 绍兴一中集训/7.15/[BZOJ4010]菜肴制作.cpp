//https://www.luogu.org/problemnew/show/P3243
/*
������Ŀ�������뵽�������򡣵������Ҫ���ֵ�����С�����У��Ǿʹ��ˡ�
���Ծٳ�������44�ֲ��ȣ�����Ϊ<2,4><3,1>
��ô�ֵ�����С����2,3,1,4����ĿҪ������Ž���3,1,2,4
�������ǣ����Է��֣�������һ�������ںϷ���Χ�ھ����ܴ���ô�����Ǿ��������ġ�
��Ϊ��������һ��������xx����ô����xx֮��������������ᱻ�ŵ����һ��λ�á�
�������Ϳ�����ǰ������С��xx������������ǰ������xx��������ȻҲ�ܿ�ǰ��������xx��λ���Ѿ��̶������û���ã����ﵽ��Ŀ��Ŀ�ꡣ
��ˣ����Ž���Ƿ��������������У������е��ֵ����������С�

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
