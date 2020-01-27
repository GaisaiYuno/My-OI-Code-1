#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#define INF 0x3f3f3f3f
#define maxlogv 32
#define maxn 50000
using namespace std;
struct persist_trie{
	int root[maxn+5];
	int ch[maxn*35+5][2];
	int sz[maxn*35+5];
	int ptr;
	void insert(int pos,int val){
		int now=root[pos]=++ptr;
		int last=root[pos-1];
		for(int i=maxlogv-1;i>=0;i--){
			int k=(val>>i)&1;
			ch[now][k]=++ptr;
			ch[now][k^1]=ch[last][k^1];
			now=ch[now][k];
			last=ch[last][k]; 
			sz[now]=sz[last]+1;	
		}
		
	}
	int query(int l,int r,int val){
		int now=root[r];
		int last=root[l-1];
		int ans=0;
		for(int i=maxlogv-1;i>=0;i--){
			int k=(val>>i)&1;
			int cnt=sz[ch[now][k^1]]-sz[ch[last][k^1]];
			if(cnt){
				now=ch[now][k^1];
				last=ch[last][k^1];
				ans=ans<<1|1;
			}else{
				now=ch[now][k];
				last=ch[last][k];
				ans=ans<<1;
			}
		}
		return ans;
	}
}T;

int n;
struct node{
	int val;
	int pos;
	friend bool operator < (node p,node q){
		return p.val>q.val;
	}
}a[maxn+5];

set<int>pos;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);
		a[i].pos=i;
	}
	for(int i=1;i<=n;i++) T.insert(i,a[i].val);
	sort(a+1,a+1+n); 
	pos.insert(-2);
	pos.insert(-1);
	pos.insert(INF-1);
	pos.insert(INF);
	pos.insert(a[1].pos);
	int ans=0;
	for(int i=2;i<=n;i++){//从大到小,这样插入到set里位置的值的都比a[i]大 
		set<int>::iterator itr=pos.lower_bound(a[i].pos),itl=itr;
		itr++;
		itl--;
		itl--;
		int l=max(*itl+1,1),r=min(*itr-1,n);//找出a[i]这个次大值的作用范围 
		if(l!=r) ans=max(ans,T.query(l,r,a[i].val));
		pos.insert(a[i].pos);
	}
	printf("%d\n",ans);
}
