#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack> 
#include<algorithm>
#include<cmath>
#define maxn 100005 
#define ForMyLove return 0;
using namespace std;
int n,q;
int a[maxn];
int lbound[maxn],rbound[maxn]; 
long long d[maxn];
struct node{
	int pos;
	int value;
	node(){
		
	}
	node(int i,int x){
		pos=i;
		value=x;
	}
}; 
stack<node>s;
int main(){
//	freopen("dyf.in","r",stdin);
	int l,r;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) d[i]=abs(a[i]-a[i-1]);
	for(int i=1;i<=n;i++){
		node now;
		while(!s.empty()){
			now=s.top();
			if(d[i]>now.value){
				rbound[now.pos]=i-1;
				s.pop();
			}else break;
		}
		if(s.size()==0) lbound[i]=1;
		else{
			now=s.top();
			lbound[i]=now.pos+1;
		}
		s.push(node(i,d[i]));
	}
	while(!s.empty()){
		node now=s.top();
		rbound[now.pos]=n;
		s.pop();
	}
	while(q--){
		scanf("%d %d",&l,&r);
		long long ans=0;
		for(int i=l+1;i<=r;i++){
			long long left=max(l+1,lbound[i]);
			long long right=min(r,rbound[i]);
			ans=ans+(i-left+1)*(right-i+1)*d[i];
		}
		printf("%I64d\n",ans);
	}
} 
