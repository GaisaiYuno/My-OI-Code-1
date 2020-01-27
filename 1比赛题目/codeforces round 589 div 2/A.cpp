#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int l,r;
int vis[15]; 
bool check(int x){
	for(int i=0;i<=9;i++) vis[i]=0;
	while(1){
		vis[x%10]++;
		if(x<10) break;
		x/=10;
	}
	for(int i=0;i<=9;i++) if(vis[i]>1) return 0;
	return 1;
}
int main(){
	scanf("%d %d",&l,&r);
	for(int i=l;i<=r;i++){
		if(check(i)){
			printf("%d\n",i);
			return 0;
		} 
	}
	printf("-1\n");
}

