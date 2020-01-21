#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2000000  
#define maxc 52
using namespace std;
typedef int ll;
struct Trie{
	int ch[maxn+5][maxc+1];
	ll cnt[maxn+5];
	inline int get_id(char c){
		if(c>='A'&&c<='Z') return c-'A';
		else if(c>='a'&&c<='z') return c-'a'+26;
		else return 52;
	}	
	int ptr;
	void insert(char *s,ll &ans){
		int x=0;
		int len=strlen(s+1);
		for(int i=1;i<=len;i++){
			int c=get_id(s[i]);
			if(!ch[x][c]) ch[x][c]=++ptr;
			x=ch[x][c];
			cnt[x]++;
			ans=max(ans,cnt[x]*i);
		}
	}
}T;

int n;
char in[maxn+5]; 
ll ans=0;
int main(){
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		gets(in+1);
		T.insert(in,ans);
	}	
	printf("%d\n",ans);
} 
