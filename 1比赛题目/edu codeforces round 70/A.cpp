#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
using namespace std;
int t;
int n,m;
char a[maxn+5];
char b[maxn+5];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",a+1);
		scanf("%s",b+1);
		n=strlen(a+1);
		m=strlen(b+1);
		reverse(a+1,a+1+n);
		reverse(b+1,b+1+m);
		int x=1;
		for(int i=1;i<=m;i++){
			if(b[i]!='0'){
				x=i;
				break;
			}
		} 
		int y=1;
		for(int i=x;i<=n;i++){
			if(a[i]!='0'){
				y=i;
				break;
			}
		}
		printf("%d\n",y-x);
	}
}

