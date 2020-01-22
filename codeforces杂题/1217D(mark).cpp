//������ⷢ���Լ��븴����
//����һ����(u,v) 
//���u>v���죬������������������
//��Ϊ������߹�һ�����ص����Ĺ����У������ĵ���Ų�����ʼ�յ������ߵ��������Ի��߲���ȫ��ͬɫ�� 
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
	if(topo_sort()){//�޻� 
		printf("1\n");
		for(int i=1;i<=m;i++) printf("1 ");
	}else{
		printf("2\n");
		for(int x : ans) printf("%d ",x); 
	}
}

