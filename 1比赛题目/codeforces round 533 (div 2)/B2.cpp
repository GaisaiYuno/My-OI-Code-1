/*
[El Psy Congroo]
For Selina

Problem:
Source:Codeforces round 533 (div 2)
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 200005
using namespace std;
int n,k;
char s[maxn];
using namespace std;
int solve(char c){
	int now=0,ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]==c) now++;
		else{
			ans+=now/k;
			now=0;
		}
	}
	if(s[n]==c)ans+=now/k;
	return ans;
}
int main(){
	scanf("%d %d",&n,&k);
	scanf("%s",s+1);
	int ans=0;
	for(char i='a';i<='z';i++){
		ans=max(ans,solve(i));
	}
	printf("%d\n",ans);
}

