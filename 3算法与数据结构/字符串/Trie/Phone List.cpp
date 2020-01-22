#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10000 
#define maxs 15
using namespace std;
int t,n;
char str[maxn+5][15];

struct Trie{
	int ch[maxn*maxs+5][maxs+5];
	int val[maxn*maxs+5];
	int sz;
	int get_id(char c){
		return c-'0';
	}
	void ini(){
		sz=0;
		memset(ch,0,sizeof(ch));
		memset(val,0,sizeof(val));
	} 
	void insert(char *s){
		int x=0; 
		int n=strlen(s+1);
		for(int i=1;i<=n;i++){
			int c=get_id(s[i]);
			if(!ch[x][c]) ch[x][c]=++sz;
			x=ch[x][c];
		}
		val[x]=1;
	}
	bool query(char *s){
		int x=0;
		int n=strlen(s+1);
		for(int i=1;i<=n;i++){
			int c=get_id(s[i]);
			if(val[x]) return 1;
			x=ch[x][c];
		}
		return 0;
	}	
}T;
int main(){
	scanf("%d",&t);
	while(t--){
		T.ini();
		scanf("%d",&n);
//		bool flag=true;
		for(int i=1;i<=n;i++){
			scanf("%s",str[i]+1);
			T.insert(str[i]);
//			printf("%d %d huaji\n",i,n);
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(T.query(str[i])){
				flag=false;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
} 
