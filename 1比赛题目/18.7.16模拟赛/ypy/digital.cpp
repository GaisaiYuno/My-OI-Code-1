#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef unsigned long long ull;
int k,w;
ull ans;
int po2;
int used[10][1024];
void dfs(int digit,int deep,int last){
	if(deep==digit){
		ans++;
		return;
	}
	for(int i=last+1;i<po2;i++){
		 dfs(digit,deep+1,i);
	}
}
int main(){
	freopen("digital.in","r",stdin);
	freopen("digital.out","w",stdout);
	scanf("%d %d",&k,&w);
	po2=pow(2,k);
	ans=0;
	int t=pow(2,w-k*(w/k))-1;
	dfs(w/k,0,0);
	for(int i=1;i<=t;i++) dfs(w%k+1,0,i);
	cout<<ans;
}
