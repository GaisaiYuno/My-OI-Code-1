#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 15
using namespace std;
int n;
int t[maxn],d[maxn]; 
int res[maxn];
int main(){
	scanf("%d",&n);
	int digit=0;
	while(n){
		d[++digit]=n%10;
		n/=10;
	}
	int ans=0;
	for(int i=1;i<=digit;i++){
		ans=max(ans,d[i]); 
	}
	for(int i=1;i<=ans;i++){
		for(int j=digit;j>=1;j--){
			if(d[j]>0){
				res[i]=res[i]*10+1;
				d[j]--;	
			}else{
				res[i]=res[i]*10; 
			} 
		}
	} 
	printf("%d\n",ans); 
	for(int i=1;i<=ans;i++){
		printf("%d ",res[i]); 
	}
}
