//Tarjan+���˲����ж�?�����������dfs 
//xiΪA��xjΪB ת��Ϊ xiΪB��xjΪA 
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring> 
#define maxn 1000 
using namespace std;
int n,m;
vector<int>E[maxn*2+5];
void add_edge(int u,int v){
//	printf("%d %d\n",u,v);
	E[u].push_back(v);
}
int mark[maxn*2+5];
void dfs(int x){
	mark[x]=1;
	for(int y : E[x]){
		if(!mark[y]) dfs(y);
	}
}

bool check(int x){
	for(int i=1;i<=n*2;i++) mark[i]=0;
	dfs(x);
	for(int i=1;i<=n;i++){
		if(mark[i]&&mark[i+n])  return 0;
	} 
	return 1;
} 

char ans[maxn+5];
int main(){
	char op1[2],op2[2];
	int u,v,p,q;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %s %d %s",&u,op1,&v,op2);
		if(op1[0]=='Y') p=1;
		else p=0;
		if(op2[0]=='Y') q=1;
		else q=0;
		add_edge(u+n*p,v+n*(1-q));
		/*
        iΪY��i+nΪN
        ������⣬���op1��op2ΪY,N
        ��ô��һ��ѯ����N�������㣬��Ӧ�ĵ����u+1*n,�ڶ���ѯ����N,���㣬��Ӧ�ĵ����v+1*n
        */
		add_edge(v+n*q,u+n*(1-p));
	}
	bool flag1,flag2;
	for(int i=1;i<=n;i++){
		flag1=check(i);
		flag2=check(i+n);
		if(!flag1&&!flag2){
			printf("IMPOSSIBLE\n");
			return 0;
		}else if(flag1&&!flag2){
			ans[i]='Y';
		}else if(!flag1&&flag2){
			ans[i]='N';
		}else{
			ans[i]='?';
		} 
	}
	for(int i=1;i<=n;i++) printf("%c",ans[i]);
}


