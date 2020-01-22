#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
using namespace std;
int n;
char s[maxn+5];
int vis[10];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='L'){
			for(int j=0;j<=9;j++){
				if(!vis[j]){
					vis[j]=1;
					break;
				}
			}
		}else if(s[i]=='R'){
			for(int j=9;j>=0;j--){
				if(!vis[j]){
					vis[j]=1;
					break;
				}
			}
		}else{
			vis[s[i]-'0']=0;
		}
	}
	for(int j=0;j<=9;j++) printf("%d",vis[j]);
}

