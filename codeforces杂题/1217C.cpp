#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 200000
using namespace std;
int t,n;
char s[maxn+5];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int last=0;//上一个1的位置 
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				int len=0;
				for(int j=i;j<=min(i+20,n);j++){
					len=len*2+s[j]-'0';
					//补0，左边界为j-len+1 
					if(j-len+1<=last) break;//如果超过了上一个1的位置，就不合法 
					ans++;
				}
				last=i;
			}
			 
		}
		printf("%d\n",ans);
	}
}

