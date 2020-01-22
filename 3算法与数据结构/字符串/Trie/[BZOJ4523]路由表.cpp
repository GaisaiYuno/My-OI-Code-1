#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define maxn 1000000
#define INF 0x3f3f3f3f
using namespace std;
int m;

struct Trie{
	int sz;
	int ch[maxn*32+5][2];
	int val[maxn*32+5];
	void insert(unsigned int v,int len,int tim){
		int x=0; 
		for(int i=31,j=1;j<=len;i--,j++){
			int c=(v>>i)&1;
			if(!ch[x][c]) ch[x][c]=++sz;
			x=ch[x][c];
		} 
		val[x]=tim;
	}
	int query(unsigned int v,int l,int r){
		stack<int>stk;
		int x=0; 
		for(int i=31;i>=0;i--){
			int c=(v>>i)&1;
			if(val[x]){
				while(!stk.empty()&&stk.top()>val[x]) stk.pop();
				stk.push(val[x]);
			}
			if(!ch[x][c]) break;
			x=ch[x][c];
		}
		int ans=0;
		int mint=INF;
		while(!stk.empty()){
			int t=stk.top();
			if(t>=l&&t<=r) ans++;
			stk.pop();
		}
		return ans;
	}
}T;
int main(){
	char cmd[2];
	scanf("%d",&m);
	int tim=0;
	int len;
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='A'){
			unsigned int x,y,z,w;
			unsigned int ans=0;
			scanf("%d.%d.%d.%d/%d",&x,&y,&z,&w,&len);
			ans=x;
			ans=(ans<<8)+y;
			ans=(ans<<8)+z;
			ans=(ans<<8)+w;
			T.insert(ans,len,++tim);
		}else{
			unsigned int x,y,z,w,l,r;
			unsigned int ans=0;
			scanf("%d.%d.%d.%d",&x,&y,&z,&w);
			ans=x;
			ans=(ans<<8)+y;
			ans=(ans<<8)+z;
			ans=(ans<<8)+w;
			scanf("%d %d",&l,&r);
			printf("%d\n",T.query(ans,l,r));
		} 
	}
} 
