#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int ans=0;
int cnt=0; 
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		if(u==v){
			cnt++;
			ans=i;
		}
	}
	if(cnt>=2){
		printf("0\n");
	}else{
		printf("1\n%d",ans);
	}
}
