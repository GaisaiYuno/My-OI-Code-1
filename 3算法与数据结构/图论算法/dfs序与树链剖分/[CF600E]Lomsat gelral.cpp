//��������ʽ�ϲ� 
#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<cstring>
#include<vector>
#define maxn 100000
using namespace std;
int n;
int c[maxn+5];
vector<int>E[maxn+5];

int id[maxn+5];
//������merge(x,y)��ʱ������������ʽ�ϲ���s[x]���ܻᲢ��s[y]ȥ
//Ȼ��ֱ�Ӳ�ѯs[x]��ը�ˣ�����id[x]���Ǽ�¼x��map�ϲ�֮�������� 
map<int,int>s[maxn+5];
int ans_max[maxn+5];//���ĳ��ִ��� 
long long ans_cnt[maxn+5];//��ź� 
long long res[maxn+5];
void merge(int x,int y){
	if(s[id[x]].size()<s[id[y]].size()){
		swap(id[x],id[y]);
	}
	int u=id[x],v=id[y];
	for(auto it : s[v]){
		int val=it.first;
		int cnt=it.second;
		s[u][val]+=cnt;
		if(s[u][val]>ans_max[u]){
			ans_max[u]=s[u][val];
			ans_cnt[u]=val;	
		}else if(s[u][val]==ans_max[u]){
			ans_cnt[u]+=val;
		}
	} 
}

void dfs(int x,int fa){
	for(int y : E[x]){
		if(y!=fa){
			dfs(y,x);
			merge(x,y);
		}
	}
	res[x]=ans_cnt[id[x]];
}

int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		id[i]=i;
		s[i][c[i]]=1;
		ans_max[i]=1;
		ans_cnt[i]=c[i];
	} 
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		printf("%I64d ",res[i]);
	}
}

