#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200000
using namespace std;
int n;
char s[maxn+5];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int left=0,right=0;
	int tot=0;
	int cnt=0;
	bool flag=false;
	for(int i=1;i<=n;i++){
		if(s[i]=='(') left++;
		if(s[i]==')') right++;
	}
	if(left!=right){
		printf("No\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='(') tot++;
		else{
			if(tot==0){
				cnt++;
				if(cnt>1){
					printf("No\n");
					return 0;
				}
//				flag=true;
			}else tot--;
		}
		
	}
	printf("Yes\n");
}
