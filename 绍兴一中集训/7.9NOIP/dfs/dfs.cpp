#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define maxn 100000
using namespace std;
int A,B,C,D;
int n;
vector<int>E[maxn+5];
void add_edge(int u,int v){
	E[u].push_back(v);
}

void print(){
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		int s=E[i].size();
		printf("%d ",s);
		for(int j=0;j<s;j++){
			printf("%d ",E[i][j]);
		}
		printf("\n");
	}
}

int main(){
#ifndef LOCAL
	freopen("dfs.in","r",stdin);
	freopen("dfs.out","w",stdout);
#endif
	scanf("%d %d %d %d",&A,&B,&C,&D);
	if(B==0&&C==0){
		n=A+1;
		for(int i=2;i<=n;i++){
			add_edge(1,i);
		}
		int tmp=D;
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				add_edge(i,j);
				tmp--;
				if(tmp==0) break;
				add_edge(j,i);
				tmp--;
				if(tmp==0) break;
			}
			if(tmp==0) break;
		}
		if(tmp>0){
			printf("-1\n");
			return 0;
		}
		print();
	}
	else if(D==0){
		n=A+1;
		int minv=min(B,C);
		for(int i=1;i<n;i++){
			add_edge(i,i+1);
		}
		int ti=-1,tj=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				add_edge(i,j);
				add_edge(j,i);
				minv--;
				if(minv==0){
					ti=i;
					tj=j;
					break;
				}
			}
			if(minv==0) break;
		}
//		print();
		if(ti==-1||tj==-1){
			printf("-1\n");
			return 0;
		}
		if(B>min(A,B)){
			int tmp=B-min(A,B);
			for(int i=ti;i<=n;i++){
				int st;
				if(i==ti) st=tj+1;
				else st=1;
				for(int j=st;j<=n;j++){
					add_edge(i,j);
					tmp--;
					if(tmp==0) break;
				}
				if(tmp==0) break;
			}
			if(tmp>0){
				printf("-1\n");
				return 0;
			}
		}else if(C>min(A,B)){
			int tmp=C-min(A,B);
			for(int i=ti;i<=n;i++){
				int st;
				if(i==ti) st=tj+1;
				else st=1;
				for(int j=st;j<=n;j++){
					add_edge(j,i);
					tmp--;
					if(tmp==0) break;
				}
				if(tmp==0) break;
			}
			if(tmp>0){
				printf("-1\n");
				return 0;
			}
		}
		print();
	}else{
		printf("-1\n");
	}
}
