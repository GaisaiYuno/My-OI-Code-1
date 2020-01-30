#include<iostream>
#include<cstdio>
#include<set>
#define maxn 100000
using namespace std;
int n,q; 
int a[3][maxn+5];
int is_block(int x,int y){
	int x2=3-x;
	int cnt=0;
	if(a[x2][y]) cnt++;
	if(a[x2][y-1]) cnt++;
	if(a[x2][y+1]) cnt++;
	return cnt;
}
int main(){
	int x,y;
	scanf("%d %d",&n,&q);
	int cnt=0;
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x,&y);
//		cnt-=is_block(x,y);
		a[x][y]^=1;
		if(a[x][y]) cnt+=is_block(x,y);
		else cnt-=is_block(x,y);
//		printf("%d ",cnt);
		if(cnt==0) puts("Yes");
		else puts("No"); 
		
	}
}

