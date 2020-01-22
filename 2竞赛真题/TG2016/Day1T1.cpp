#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int n,m;
int dir[maxn];
string job[maxn]; 
int main(){
	int x,y,now;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&dir[i]);
		cin>>job[i];
	}
	now=0;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		if(dir[now]==x){
			y*=-1;
		}
		now=(now+y+n)%n;
	}
	cout<<job[now];
} 
