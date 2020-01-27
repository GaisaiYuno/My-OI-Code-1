//http://119.29.55.79/contest/114/problem/1 
#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 15000
using namespace std;
char s[maxn+5];
int nex[maxn+5];
int n,k;
int ans=0; 
void get_nex(char *s,int n){
	nex[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&s[j+1]!=s[i]) j=nex[j];
		if(s[j+1]==s[i]) j++;
		nex[i]=j;
	}
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&s[j+1]!=s[i]) j=nex[j];
		if(s[j+1]==s[i]) j++;
		while(j*2>=i) j=nex[j];
		if(j>=k) ans++;
	}
}
int main(){
	scanf("%s",s+1);
	scanf("%d",&k);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		get_nex(s+i-1,n-i+1);
		//把每个字串看成单独一个字符串求答案，指针简化代码 
	}
	printf("%d\n",ans);
}

