#include<iostream>
#include<cstdio>
#define maxn 128
using namespace std;
int t;
int n;
char s[maxn+5];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			if(s[1]>='A'&&s[1]<='Z') printf("%c",s[1]);
			else printf("%c",s[1]-'a'+'A');
		}
		printf("\n");
	}
}

