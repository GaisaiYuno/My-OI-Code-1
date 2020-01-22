#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,q,a[1001],b,c;
int pow(int x){
	if(x==0)return 1;
	else return 10*pow(x-1);
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&b,&c);
		for(int j=1;j<=n;j++){
			if(c>a[j])continue;
			if((a[j]-c)%pow(b)==0){
				printf("%d\n",a[j]);
				break;
			}
			if(j==n)printf("-1\n");
		}
	}
	return 0;
}
