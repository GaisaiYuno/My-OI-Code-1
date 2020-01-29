#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10000005
using namespace std;
int n;
long long x,y;
long long mark[maxn]; 
void dfs(int i,long long t){
	if(mark[i]&&t>mark[i]) return;
	if(i>n) return;
	mark[i]=t;
	if(i<n)  dfs(i+1,t+x);
	if(i!=0) dfs(i-1,t+x);
	if(i!=0) dfs(i*2,t+y);
}
int main(){
	cin>>n>>x>>y;
	dfs(0,0);
	cout<<mark[n]; 
}
