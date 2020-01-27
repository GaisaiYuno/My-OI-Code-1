#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define maxl 1000000
#define seed 1314159
#define mod 1004535809ll
using namespace std;
typedef unsigned long long ull;
int n;
char s[maxl+5];
string word[maxn+5];
vector<ull>pre[maxn+5];
vector<ull>nex[maxn+5];
ull poww[maxl+5];
int calc(int x,int y){
	int lenx=word[x].length(),leny=word[y].length();
	int len=min(word[x].length(),word[y].length());
	int ans=0;
	for(int i=1;i<=len;i++){
		if(nex[x][lenx-i]==pre[y][i-1]) ans=max(ans,i);
	}
	return ans;
}
int main(){
	poww[0]=1;
	for(int i=1;i<=maxl;i++) poww[i]=poww[i-1]*seed%mod;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		word[i]=string(s);
		int len=word[i].length();
		pre[i].resize(len);
		nex[i].resize(len); 
		pre[i][0]=word[i][0];
		for(int j=1;j<len;j++){
			pre[i][j]=(pre[i][j-1]*seed%mod+word[i][j])%mod;
		}
		nex[i][len-1]=word[i][len-1];
		for(int j=len-2;j>=0;j--){
			nex[i][j]=(nex[i][j+1]+poww[len-1-j]*word[i][j]%mod)%mod;
		}
	}
	int last=0;
	for(int i=1;i<n;i++){
		int len=calc(i,i+1);
		int leni=word[i].length();
		for(int j=last;j<leni;j++) putchar(word[i][j]);
		last=len;
	}
	for(int j=last;j<word[n].length();j++) putchar(word[n][j]);
}

