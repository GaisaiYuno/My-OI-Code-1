#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 2000 
using namespace std;
int n,m;
map<char,int>vis;
char s[maxn+5][maxn+5];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n-m+1;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-m+1;j++){
			vis[s[j][i]]++;
		}
		int maxcnt=0;
		char ans;
		for(map<char,int>::iterator it=vis.begin();it!=vis.end();it++){
			if(it->second>maxcnt){
				maxcnt=it->second;
				ans=it->first;
			}
		}
		printf("%c",ans);
		vis.clear();
	}
}

