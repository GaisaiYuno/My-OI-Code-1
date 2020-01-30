#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 200000
using namespace std;
int n;
int a[maxn+5];
int sum[maxn+5];
char s[maxn+5];
int last[maxn+5];
void work(int x){
	while(x){
		a[last[x]]=0;
		x--;
//		if(x==0) break;
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			if(sum[i-1]==0) sum[i]=sum[i-1];
			else sum[i]=sum[i-1]-1;
		}else{
			sum[i]=sum[i-1]+1;
			last[sum[i]]=i;
		}
	} 
	work(sum[n]);
	for(int i=1;i<=n;i++) printf("%d",a[i]);
}

