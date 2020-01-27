#include<iostream>
#include<cstdio>
using namespace std;
int t; 
const int area[10]={1,0,0,0,1,0,1,0,2,1};
int f(int x){
	if(x==0) return area[0];
	else{
		int ans=0; 
		while(x){
			ans+=area[x%10];
			x/=10;
		}
		return ans;
	}
}
int g(int k,int x){
	int last=0;
	for(int i=1;i<=k;i++){
		x=f(x);
		last=i;
		if(x==0||x==1||x==2) break;
	}
	if(last==k) return x;
	else{
		int left=k-last;
		if(x==0){
			if(left%2==0) return 0;
			else return 1;
		}else if(x==1||x==2){
			if(left%2==0) return 1;
			else return 0;
		} 
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		int x,k;
		scanf("%d %d",&x,&k);
		printf("%d\n",g(k,x));
	}
}

