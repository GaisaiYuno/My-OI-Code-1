#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char word[105];
int num[26],used[105];
int len;
int minn,maxn;
int is_prime(int x){
	if(x==1||x==0) return 0;
	if(x%2==0&&x!=2) return 0;
	for(int i=3;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
int main(){
	scanf("%s",word);
	len=strlen(word);
	for(int i=0;i<26;i++){
		for(int j=0;j<len;j++){
			if(used[j]==0&&word[j]=='a'+i){
				used[j]=1;
			    num[i]++;
			}
		}
	}
	minn=1000000,maxn=0;
	for(int i=0;i<26;i++){
		if(num[i]!=0&&num[i]<minn) minn=num[i];
		if(num[i]!=0&&num[i]>maxn) maxn=num[i];
	}
	if(is_prime(maxn-minn)==1) printf("Lucky Word\n%d",maxn-minn);
	else printf("No Answer\n0");
	return 0;
}
