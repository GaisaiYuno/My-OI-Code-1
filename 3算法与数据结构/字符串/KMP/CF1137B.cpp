#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 500000
using namespace std;
int n,m;
char s[maxn+5],t[maxn+5];
void get_nex(char* s,int n,int* nex){
	nex[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j&&s[j+1]!=s[i]) j=nex[j];
		if(s[j+1]==s[i]) j++;
		nex[i]=j;
	} 
}

int nex[maxn+5];
int cnt[2];
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1),m=strlen(t+1);
	get_nex(t,m,nex);
	for(int i=1;i<=n;i++) cnt[s[i]-'0']++;
	for(int i=1,j=1;i<=n;i++){
		if(cnt[t[j]-'0']>0){
			putchar(t[j]);
			cnt[t[j]-'0']--;
		}else break;
		if(j==m) j=nex[j];
		j++;
	}
	while(cnt[0]>0){
		putchar('0');
		cnt[0]--;
	}
	while(cnt[1]>0){
		putchar('1');
		cnt[1]--;
	}
	
}

