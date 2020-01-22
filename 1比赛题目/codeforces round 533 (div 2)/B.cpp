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
unsigned long long f[maxn],p[maxn];
map<unsigned long long,int>vis;
int main(){
	scanf("%d %d",&n,&k);
	scanf("%s",s+1);
	p[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]*131+(s[i]-'a'+1);
		p[i]=p[i-1]*131;
	}
	for(int i=1;i+k-1<=n;i++){
		int l=i,r=i+k-1;
		vis[f[r]-f[l-1]*p[r-l+1]]++;
	}
	int ans=0;
	map<unsigned long long,int>::iterator it;
	for(it=vis.begin();it!=vis.end();it++){
		ans=max(ans,it->second);
	} 
	printf("%d\n",ans);
}

