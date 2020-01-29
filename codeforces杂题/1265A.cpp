#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#define maxn 100000
using namespace std;
int t,n;
char s[maxn+5];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		s[0]='?';
		s[n+1]='?';
		for(int i=1;i<=n;i++){
			if(s[i]!='?') continue;
			if(isalpha(s[i-1])&&isalpha(s[i+1])){
				for(char x='a';x<='c';x++){
					if(x!=s[i-1]&&x!=s[i+1]){
						s[i]=x;
						break;
					}
				}
			}else if(isalpha(s[i-1])){
				for(char x='a';x<='c';x++){
					if(x!=s[i-1]){
						s[i]=x;
						break;
					}
				}
			}else if(isalpha(s[i+1])){
				for(char x='a';x<='c';x++){
					if(x!=s[i+1]){
						s[i]=x;
						break;
					}
				}
			}else{
				s[i]='a';
			}
		}
		bool flag=true;
		for(int i=1;i<n;i++){
			if(s[i]==s[i+1]){
				flag=false;
				break;
			}
		}
		if(!flag) printf("-1\n");
		else{
			for(int i=1;i<=n;i++) printf("%c",s[i]);
			printf("\n");
		}
	}
}

