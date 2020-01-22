#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int n;
char a[maxn];
void conv(char *s){
	int len=strlen(s);
	if(len<=10){
		 printf("%s\n",s); 
		 return;
	} 
	else{
		printf("%c%d%c\n",s[0],len-2,s[len-1]);
	}
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s",a);
		conv(a);
	}
}
