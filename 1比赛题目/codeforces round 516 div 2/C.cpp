#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100005
using namespace std;
int n;
char s[maxn];
int cnt[26];
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		cnt[s[i]-'a']++; 
	}
	for(int i=0;i<26;i++){
		while(cnt[i]){
			printf("%c",'a'+i);
			cnt[i]--;
		}
	}
}

