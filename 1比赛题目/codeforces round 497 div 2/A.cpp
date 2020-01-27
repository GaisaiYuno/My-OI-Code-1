#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int is_vowel(char c){
	if(c=='a') return 1;
	if(c=='e') return 1;
	if(c=='i') return 1;
	if(c=='o') return 1;
	if(c=='u') return 1;
	else return 0;
}
char a[maxn];
int main(){
	scanf("%s",a+1);
	int len=strlen(a+1);
	for(int i=1;i<=len;i++){
		if(is_vowel(a[i])) continue;
		else if(a[i]=='n') continue;
		else{
			if(!is_vowel(a[i+1])){
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
}
