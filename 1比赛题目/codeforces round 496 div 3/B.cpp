#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200005
using namespace std;
char a[maxn],b[maxn];
int main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	int n=strlen(a+1);
	int m=strlen(b+1);
	int k=min(n,m);
	int cnt=0;
	for(int i=0;i<k;i++){
		if(a[n-i]==b[m-i]) cnt++;
		else break;
	}
	printf("%d\n",n+m-cnt*2);
}
