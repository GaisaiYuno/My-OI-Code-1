#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
using namespace std;
int T,n,m;
char s[maxn+5],t[maxn+5];
bool check(int x){
	static int cnt;
	cnt=0;
	for(int i=x;i<=x+m-1;i++){
		if(s[i]!=t[i-x+1]){
			cnt++;
			if(cnt>3) return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		int ans=0; 
		for(register int i=1;i<=n-m+1;i++){
			if(check(i)){
//				printf("db: %d\n",i);
				ans++;
			}
		} 
		printf("%d\n",ans);
	}
} 
