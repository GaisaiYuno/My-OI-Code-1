#include<iostream>
#include<cstdio>
#define maxn 105
using namespace std;
int n;
char t[maxn];
char s[maxn]; 
int cnt[27];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",t);
		s[i]=t[0];
		cnt[s[i]-'a']++;
	}
	int ans=0;
	for(int i=0;i<26;i++){
		if(cnt[i]!=0){
			int l=cnt[i]/2;
			int r=cnt[i]-l;
			ans+=l*(l-1)/2;
			ans+=r*(r-1)/2; 
		}
	}
	printf("%d\n",ans);
}

