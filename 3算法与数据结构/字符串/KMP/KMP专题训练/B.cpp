#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
#define maxn 1000000 
using namespace std;
typedef long long ll;
int t,n;
char s[maxn+5];
int nex[maxn+5];
ll cnt[maxn+5];
void ini(){
	for(int i=1;i<=n;i++) nex[i]=cnt[i]=0;
}
int main(){
	scanf("%d",&t);
	while(t--){ 
		scanf("%s",s+1);
		n=strlen(s+1);
		ini();
		cnt[1]=1;//不带限制(可以相交)的字串数量 
		for(int i=2,j=0;i<=n;i++){
			while(j>0&&s[j+1]!=s[i]) j=nex[j];
			if(s[j+1]==s[i]) j++;
			nex[i]=j;
			cnt[i]=cnt[j]+1;
		}	
		ll ans=1;
		for(int i=2,j=0;i<=n;i++){
			while(j>0&&s[j+1]!=s[i]) j=nex[j];
			if(s[j+1]==s[i]) j++;
			while(j*2>i) j=nex[j]; 
			ans=ans*(cnt[j]+1)%mod; 
//			cnt[i]=cnt[j]+1;
		} 
		
		printf("%lld\n",ans);
	} 
}
