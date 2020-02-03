#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
int a[3005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
		bool flag=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]%2==1&&a[j]%2==1){
					flag=1;
					printf("%d%d\n",a[i],a[j]);
					break;
				}
			}
			if(flag==1) break; 
		}
		if(flag==0) printf("-1\n"); 
	}
}

