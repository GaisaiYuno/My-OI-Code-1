#include<iostream>
#include<cstdio>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int t;
int n,x,y,d;
int up(int x,int y){
	if(x%y==0) return x/y;
	else return x/y+1;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d",&n,&x,&y,&d);
		if(abs(y-x)%d==0){
			printf("%d\n",abs(y-x)/d);
		}else{
			int ans=INF;
			if(abs(y-n)%d==0){
				ans=min(ans,abs(n-y)/d+up(n-x,d));
			}
			if(abs(y-1)%d==0){
				ans=min(ans,abs(y-1)/d+up(x-1,d));
			}
			if(ans<INF) printf("%d\n",ans);
			else printf("-1\n");
		}
	}
}
