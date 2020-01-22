#include<iostream>
#include<cstdio>
#define maxn 200000 
using namespace std;
int n;
int a[maxn+5];
struct Trie{
	int ch[maxn*31+5][2];
	int sz;
	void insert(int v){
		int x=0;
		for(int i=31;i>=0;i--){
			int c=(v>>i)&1;
			if(!ch[x][c]) ch[x][c]=++sz;
			x=ch[x][c];
		}
	}
	int query(int v){
		int x=0;
		int ans=0;
		for(int i=31;i>=0;i--){
			int c=(v>>i)&1;
			if(ch[x][c^1]){
				ans=ans<<1|1;
				x=ch[x][c^1];
			}
			else{
				ans=ans<<1;
				x=ch[x][c];
			}
			
		}
		return ans;
	}
}T; 

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		T.insert(a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,T.query(a[i]));
	}
	printf("%d\n",ans);	
}
