#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 101
using namespace std;
char word[MAXN];
int cnt[27];
int maxn,minn;
int is_prime(int x){
	if(x==0||x==1) return 0;
	if(x==2) return 1;
	if(x%2==0) return 0;
	for(int i=3;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
int main(){
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	scanf("%s",word);
	int n=strlen(word);
	for(int i=0;i<n;i++){
		cnt[word[i]-'a']++;
	}
	maxn=0;
	minn=MAXN;
	for(int i=0;i<26;i++){
		maxn=max(cnt[i],maxn);
		if(cnt[i]!=0) minn=min(cnt[i],minn);
	}
	if(is_prime(maxn-minn)) printf("Lucky Word\n%d\n",maxn-minn);
	else printf("No Answer\n0\n");
} 
