#include<iostream>
#include<cstdio>
#define maxn 1005
using namespace std;
int n;
int x[maxn],y[maxn];
int main(){
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			x[i]=i/2+1;
			y[i]=i/2+1;
		}else{
			x[i]=x[i-1];
			y[i]=x[i-1]+1;
		}
		ans=max(ans,x[i]);
		ans=max(ans,y[i]);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		printf("%d %d\n",x[i],y[i]);
	}
}

