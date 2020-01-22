#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 25
using namespace std;
int carda[maxn],cardb[maxn];
int suma,sumb;
int is_undercut(int x,int y){
	if(x-y==1||y-x==1) return 1;
	else return 0;
}
int judge(int x,int y){
	if(is_undercut(x,y)){
		if((x==1&&y==2)||(x==2&&y==1)) return 6;
		else return x+y;
	}
	else return max(x,y);
}
int n,cnt=0;
int main(){
	//freopen("test.txt","r",stdin);
	while(cin>>n&&n!=0){
		cnt++;
		for(int i=1;i<=n;i++) cin>>carda[i];
		for(int i=1;i<=n;i++) cin>>cardb[i];
		suma=sumb=0;
		for(int i=1;i<=n;i++){
			if(carda[i]>cardb[i]){
				if(is_undercut(carda[i],cardb[i])) sumb+=judge(carda[i],cardb[i]);
				else suma+=judge(carda[i],cardb[i]);
			}
			else if(carda[i]<cardb[i]){
				if(is_undercut(carda[i],cardb[i])) suma+=judge(carda[i],cardb[i]);
				else sumb+=judge(carda[i],cardb[i]);
			}
			else continue;
		}
		if(cnt!=1) printf("\n\n");
		printf("A has %d points. B has %d points.",suma,sumb);
	}
}
