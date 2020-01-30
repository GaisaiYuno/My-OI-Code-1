#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100
using namespace std;
int n;
char s[maxn+5];
int main(){
	scanf("%s",s);
	n=strlen(s);
//	printf("%d\n",n);
	bool flag=1;
	int ans=0;
	for(int i=n-1;i>0;i--){
		if(s[i]!='0') flag=0;
	} 
//	printf("%d\n",flag); 
	if(flag) printf("%d\n",n/2);
	else printf("%d\n",(n+1)/2);
}

