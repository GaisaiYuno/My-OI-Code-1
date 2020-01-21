#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxl 60
#define maxs 10
using namespace std;
int n; 
struct persist_trie{
	int root[maxn+5];
	int sz[maxn+5]; 
	int ch[maxn*maxl+5][maxs];
	inline get_id(char c){
		return c-'a';
	}
	int ptr;
	void insert(char *s,int pos,int type){
		int now=root[pos]=++ptr,last=root[pos-1];
		int len=strlen(s+1);
		for(int i=1;i<=len;i++){
			int c=get_id(s[i]);
			for(int j=0;j<=maxs-1;j++) ch[now][j]=ch[last][j];
			ch[now][c]=++ptr;
			now=ch[now][c];
			last=ch[last][c];
			sz[now]=sz[last]+type;
		}
//		sz[now]=sz[last]+type;
	}
	int query(char *s,int pos){
		int len=strlen(s+1);
		int now=root[pos];
		for(int i=1;i<=len;i++){
			int c=get_id(s[i]);
			if(ch[now][c]==0) return -1;
			now=ch[now][c];
		}
		return sz[now];
	} 
}T;
int tsz=0;
int root_id[maxn+5];
bool check(int mid,char *s,int val){
	if(T.query(s,root_id[mid])>val) return 1;
	else return 0;
}
int solve(char *s,int tim,int val){
	int l=1,r=tim;
	int mid,ans=tim+1;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid,s,val)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	if(ans==tim+1) return -1; 
	else return ans;
} 

char in[maxl+5];
int main(){
	int k,a,b,c;
	int lastans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		scanf("%s",in+1);
		if(k==1){
			root_id[i]=root_id[i-1]+1;
			T.insert(in,root_id[i],1);	
		}else if(k==2){
			root_id[i]=root_id[i-1]+1;
			T.insert(in,root_id[i],-1);
		}else{
			root_id[i]=root_id[i-1];
			scanf("%d %d %d",&a,&b,&c);
			int cnt=(1ll*a*abs(lastans)+b)%c;
			lastans=solve(in,i,cnt);
			printf("%d\n",lastans);	
		} 
	}
}

