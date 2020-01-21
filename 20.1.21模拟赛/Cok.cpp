#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector> 
#define maxn 1000000 
#define maxl 60
#define maxs 10
using namespace std;
int n; 
struct Trie{
	int ch[maxn+5][maxs+1];
	int f[maxn+5];
	vector<int>v[maxn+5];
	inline int get_id(char c){
		return c-'a';
	}	
	int ptr;
	void insert(char *s,int type,int tim){
		int x=0;
		int len=strlen(s+1);
		for(int i=1;i<=len;i++){
			int c=get_id(s[i]);
			if(!ch[x][c]) ch[x][c]=++ptr;
			x=ch[x][c];
			f[x]+=type;
			if(f[x]>v[x].size()){
				v[x].push_back(tim);
//				printf("v[%d] push %d\n",x,tim);
			}
		}
	}
	int query(char *s,int k){
		int x=0;
		int len=strlen(s+1);
		for(int i=1;i<=len;i++){
			int c=get_id(s[i]);
			x=ch[x][c];
			if(v[x].size()<=k) return -1;
		}
		return v[x][k];
	}
}T;

char in[maxl+5];
int main(){
	int k,a,b,c;
	int lastans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		scanf("%s",in+1);
		if(k==1){
			T.insert(in,1,i);	
		}else if(k==2){
			T.insert(in,-1,i);
		}else{
			scanf("%d %d %d",&a,&b,&c);
			int cnt=(1ll*a*abs(lastans)+b)%c;
			lastans=T.query(in,cnt);
			printf("%d\n",lastans);	
		} 
	}
}

