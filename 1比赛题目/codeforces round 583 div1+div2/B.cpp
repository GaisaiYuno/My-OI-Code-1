#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int b,g,n;
int main(){
	scanf("%d %d %d",&b,&g,&n);
	int ans=0;
	for(int i=0;i<=n;i++){
		int boy=i;
		int girl=n-i;
		if(boy<=b&&girl<=g) ans++;
	} 
	printf("%d\n",ans);
}

