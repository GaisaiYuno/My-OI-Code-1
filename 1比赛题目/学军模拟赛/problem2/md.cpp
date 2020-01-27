#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#define maxn 10
#define maxm 20
#define maxv 1000000006
using namespace std;
int n,m;
int sz[maxn+5];
inline int random(int n){
	return 1ll*rand()*rand()%n+1;	
}
inline int random(int l,int r){
	return 1ll*rand()*rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	n=random(2,maxn);
	m=random(maxm);
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++){
		int cmd=random(1,6);
		if(cmd==1){
			int t=random(n);
			int x=random(maxv);
			sz[t]++;
			printf("%d %d %d\n",cmd,t,x);
		}else if(cmd==2){
			int t=random(n);
			if(sz[t]==0){
				cmd=1;
				int t=random(n);
				int x=random(maxv);
				sz[t]++;
				printf("%d %d %d\n",cmd,t,x);
			}else{
				sz[t]--;
				printf("%d %d\n",cmd,t);
			}
		}else if(cmd==3){
			int t=random(n);
			int x=random(maxv);
			sz[t]++;
			printf("%d %d %d\n",cmd,t,x);
		}else if(cmd==4){
			int t=random(n);
			if(sz[t]==0){
				cmd=3;
				int t=random(n);
				int x=random(maxv);
				sz[t]++;
				printf("%d %d %d\n",cmd,t,x);
			}else{
				sz[t]--;
				printf("%d %d\n",cmd,t);
			}
		}else if(cmd==5){
			printf("%d %d %d\n",cmd,random(n),random(maxv));
		}else{
			int x=random(n-1),y=random(x+1,n);
			printf("%d %d %d\n",cmd,x,y);
			sz[x]+=sz[y];
			sz[y]=0;
		}
	}
}
