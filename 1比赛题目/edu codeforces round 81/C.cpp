#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<vector>
#define maxn 100000
using namespace std;
int T,n,m;
char s[maxn+5],t[maxn+5];
vector<int>pos[27];
void ini(){
	for(int i=0;i<26;i++) pos[i].clear(); 
}
int main(){
	scanf("%d",&T);
	while(T--){
		ini();
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		for(int i=1;i<=n;i++){
			pos[s[i]-'a'].push_back(i);
		}
		int last=0;
		int ans=1;
		for(int i=1;i<=m;i++){
			int c=t[i]-'a';
			if(pos[c].size()==0){
				ans=-1;
				break;
			}
			int p=upper_bound(pos[c].begin(),pos[c].end(),last)-pos[c].begin();
			if(p==(int)pos[c].size()){
				ans++;
				last=*pos[c].begin();
			}
			else last=pos[c][p]; 
//			printf("i=%d last=%d\n",i,last);
		}
		printf("%d\n",ans);
	}
}

