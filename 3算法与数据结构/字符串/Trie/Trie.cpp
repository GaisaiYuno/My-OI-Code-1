#include<iostream>
#include<cstdio>
#include<cstring>
#define maxnode 1005
#define sigma_size 26
using namespace std;
struct Trie{
	int ch[maxnode][sigma_size];
	int v[maxnode];
	int size;
	void ini(){
		size=1;
		memset(ch,0,sizeof(ch));
	}
	int getid(char c){
		return c-'a';
	}
	void insert(char *s,int val){
		int u=0;
		int n=strlen(s);
		for(int i=0;i<n;i++){
			int c=getid(s[i]);
			if(ch[u][c]==0){
				memset(ch[size],0,sizeof(ch[size]));
				v[size]=0;
				ch[u][c]=size++;
			}
			u=ch[u][c];
		}
		v[u]=val;
	}
	int query(char *s){
		int u=0;
		int n=strlen(s);
		for(int i=0;i<n;i++){
			int c=getid(s[i]);
			if(ch[u][c]==0) return 0;
			else u=ch[u][c];
		} 
		return v[u];
	}
};
Trie T;
char str[maxnode];
int val;
int main(){
	T.ini();
	while(scanf("%s",str)!=EOF){
		if(strcmp(str,"END!")==0) break;
		scanf("%d",&val);
		T.insert(str,val);
	} 
	printf("ok\n");
	while(scanf("%s",str)!=EOF){
		printf("%d\n",T.query(str));
	} 
}
