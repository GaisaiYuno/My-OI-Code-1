#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;
int n,q,i,j,a[1000+5],b,m,k,kk,pd;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(i=1;i<=q;i++){
		scanf("%d",&m);
		scanf("%d",&b);
		pd=0;
		for(j=1;j<=n;j++){
			if(m==1){
				k=a[j]%10;
				kk=b%10;
			}
			else if(m==2){
				k=a[j]%100;
				kk=b%100;
			}
			else if(m==3){
				k=a[j]%1000;
				kk=b%1000;
			}
			else if(m==4){
				k=a[j]%10000;
				kk=b%10000;
			}
			else if(m==5){
				k=a[j]%100000;
				kk=b%100000;
			}
			else if(m==6){
				k=a[j]%1000000;
				kk=b%1000000;
			}
			else if(m==7){
				k=a[j]%10000000;
				kk=b%10000000;
			}
			else if(m==8){
				k=a[j]%100000000;
				kk=b%100000000;
			}
			if(k==kk){
				pd=1;
				printf("%d\n",a[j]);
				break;
			}
		}
		if(pd==0){
			printf("-1\n");
		}
	}
	return 0;
}
