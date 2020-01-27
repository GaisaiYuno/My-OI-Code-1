#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 100005 
using namespace std;
int v[26];
char s[maxn];
long long sum[maxn];
map<long long,int>cnt;
int main(){
	for(int i=0;i<26;i++){
		scanf("%d",&v[i]);
	}
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+v[s[i]-'a'];
	}
	long long ans=0;
	for(int i=0;i<26;i++){
		cnt.clear();
		//若i~j为合法子串,则sum[j]=sum[i-1]
		//cnt记录sum的出现次数 
		for(int j=1;j<=n;j++){
			if(s[j]=='a'+i){
				ans+=cnt[sum[j-1]];
				cnt[sum[j]]++;
			}
		}
	}
	cout<<ans;
	
}
