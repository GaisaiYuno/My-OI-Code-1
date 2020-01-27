#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10000000 
using namespace std;
int t;
int n;
char a[maxn+5];
char b[maxn+5];
int cnt=0;
int main(){
	scanf("%d",&t);
	while(t--){
		int l1,l2,r1,r2;
		l1=l2=r1=r2=0;
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		bool no_sol=false;
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i]&&a[i-1]==b[i-1]){
				cnt++;
				if(cnt>2){
					no_sol=true;
					break;
				}
				if(l1==0) l1=i;
				else l2=i;
			}
			if(a[i]!=b[i]&&a[i+1]==b[i+1]){
				if(r1==0) r1=i;
				else r2=i;
			}
		}
		if(no_sol){
			printf("0\n");
		}else if(l2!=0){
			printf("6\n");

		}else if(l1!=0){
			printf("%d\n",2*(n-1));
		}else{
			printf("%lld\n",1ll*n*(n+1)/2);
		}
	}
}

