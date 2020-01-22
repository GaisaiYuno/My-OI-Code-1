#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 200000
#define maxl 50
using namespace std;
struct disjoint_set{
	int fa[maxn+5];
	void ini(int n){
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	int find(int x){
		if(fa[x]==x) return x;
		else return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
//		printf("merge %d %d\n",x,y);
		int fx=find(x),fy=find(y);
		if(fx!=fy) fa[fx]=fy;
	}
}S; 

int n;
int len[maxn+5];
char s[maxl+5];
vector<int>id[maxn+5]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int j=1;j<=len;j++){
			id[s[j]-'a'].push_back(i);
		}
	}
	S.ini(n);
	for(int i=0;i<=25;i++){
		for(int j=0;j<(int)id[i].size()-1;j++){
			S.merge(id[i][j],id[i][j+1]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(S.fa[i]==i) ans++;
	}
	printf("%d\n",ans);

}
/*
3
aaaaa
a
b 
*/ 

