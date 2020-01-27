#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100000
using namespace std;
int n,A,B,C,D;
vector<int>T[maxn+5],G[maxn+5];
int id[maxn];//deepΪi�Ľڵ��� 
vector<int>node;//���ڵ�ǰ�ڵ������ڣ�Ҳ���ǵ�ǰ�ڵ����ȵĽڵ� 
void add_edge(vector<int>* E,int u,int v){
	E[u].push_back(v);
}

int fa[maxn];
void dfs(int x){
	for(int i=0;i<T[x].size();i++){
		int y=T[x][i];
		fa[y]=x;
		if(C>0){
			for(int j=fa[x];j;j=fa[j]){
				add_edge(G,j,y);
				C--;
				if(C==0) break;
			}
		}
		if(B>0){
			for(int j=x;j;j=fa[j]){
				add_edge(G,y,j);
				B--;
				if(B==0)  break;
			}
		}
		if(D>0){
			for(int j=0;j<node.size();j++){
				add_edge(G,y,node[j]);
				D--;
				if(D==0) break;
			}	
		}
		dfs(y);
	} 
	node.push_back(x);
}

void print(){
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		int sz=G[i].size();
		printf("%d ",sz);
		for(int j=0;j<sz;j++){
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
}
int main(){
	scanf("%d %d %d %d",&A,&B,&C,&D);
	n=A+1;
	long long type1=max(A+C,B);//����+ǰ��ߵȼ��ڷ���� 
	long long type2=D;//���ߺ�������ǻ���� 
	long long maxsum=(long long)n*(n-1)/2;
	if(type1+type2>maxsum){
		printf("-1\n");
		return 0;
	}
	
	//��������������˴𰸣��������������ȡ�������
	//������������ʹ��ÿ���ڵ����֮��ǡ��=type1 
	int maxd=0;
	int sum=type1;
	id[0]=1;
	for(int i=2;i<=n;i++){
		//�������Ϊmaxd+1�ĵ����ӵı���(maxd+1),�ټ��ϰ�����(n-i)����ҵ����ϵ���С����(n-i) 
		if(maxd+1+n-i<=sum){
			add_edge(T,id[maxd],i);
			add_edge(G,id[maxd],i);
			maxd++;
			sum-=maxd;
			id[maxd]=i;
		}else{
			int tmp=sum-(n-i);//ȥ���������i��������ӵı��� 
			add_edge(T,id[tmp-1],i);
			add_edge(G,id[tmp-1],i);
			sum-=tmp;
		} 
	}
	dfs(1);
	print();
}
