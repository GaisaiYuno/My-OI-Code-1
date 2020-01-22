#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int t,n;
char s[maxn];
char s0[maxn];
int is_ok(int l,int r){
	int c1=0,c2=0,c3=0;
	for(int i=l;i<=r;i++){
		if(s[i]>='a'&&s[i]<='z') c1=1;
		if(s[i]>='A'&&s[i]<='Z') c2=1;
		if(s[i]>='0'&&s[i]<='9') c3=1;
	}
	return (c1&c2&c3);
} 
int main(){
	scanf("%d",&t);
	int is_A=0,is_a=0,is_d=0;
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		if(is_ok(1,n)) printf("%s\n",s+1);
		else{
			bool flag=false;
			for(int i=1;i<=n;i++){
				s0[i]=s[i];
			}
			for(int i=1;i<=n;i++){
				s[i]='1';
				if(is_ok(1,n)){
					printf("%s\n",s+1);
					flag=true;
					break;
				}
				s[i]='a';
				if(is_ok(1,n)){
					printf("%s\n",s+1);
					flag=true;
					break;
				}
				s[i]='A';
				if(is_ok(1,n)){
					printf("%s\n",s+1);
					flag=true;
					break;
				}
				s[i]=s0[i];
			}
			if(!flag){
				if(s[3]>='0'&&s[3]<='9'){
					s[1]='a';
					s[2]='A';
				}
				if(s[3]>='a'&&s[3]<='z'){
					s[1]='A';
					s[2]='1';
				}
				if(s[3]>='A'&&s[3]<='Z'){
					s[1]='a';
					s[2]='1';
				}
				printf("%s\n",s+1);
			}
		}
	}
} 
