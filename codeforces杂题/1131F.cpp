#include<iostream>
#include<cstdio>
#include<vector>
#define maxn 150005
using namespace std;
int id[maxn];
vector<int>v[maxn];
void merge(int a,int b){
	int x=id[a],y=id[b];
	if(x==y) return;
	else{
		if(v[x].size()<v[y].size()) swap(x,y);
		for(int p : v[y]){
			v[x].push_back(p);
			id[p]=x;
		}
	}
}

int n;
int main(){
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		id[i]=i;
		v[i].push_back(i); 
	}
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&a,&b);
		merge(a,b); 
	}
	for(int x : v[id[1]]) printf("%d ",x);
}

