#include<iostream>
#include<cstdio>
#define INF 0x3f3f3f3f
#define maxn 1005
using namespace std;
int t,n;
char s[maxn]; 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans=INF;
		for(int i=1;i<=n;i++){
			if(s[i]=='>'){
				ans=min(ans,i-1);
				break;
			}
		}
		for(int i=n;i>=1;i--){
			if(s[i]=='<'){
				ans=min(ans,n-i);
				break;
			}
		}
		printf("%d\n",ans);
	} 
}

