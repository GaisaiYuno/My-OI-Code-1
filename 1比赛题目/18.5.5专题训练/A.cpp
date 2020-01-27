#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxp 150005
using namespace std;
int p;
int a[maxp],b[maxp]; 
int main(){
	scanf("%d",&p);
	for(int i=1;i<=p;i++){
		 scanf("%d",&a[i]);
	}
	int i=0; 
	int k=1;
	int ans=0;
	for(int i=1;i<=p;i++){
		if(a[i]>=a[i-1]&&a[i]>=a[i+1]&&k==1){
			ans+=a[i];
			k=0; 
		} 
		if(a[i]<=a[i-1]&&a[i]<=a[i+1]&&k==0){
			ans-=a[i];
			k=1;
		} 
	}
	printf("%d\n",ans);
}
