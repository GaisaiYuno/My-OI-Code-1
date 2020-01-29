#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300005
using namespace std;
int n;
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int l=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;i-j*2>=l;j++){
			if(s[i]==s[i-j]&&s[i-j]==s[i-j*2]) l=i-j*2;
		}
		ans+=l;
	} 
	printf("%I64d\n",ans);
}

