//http://119.29.55.79/problem/3236 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200
#define maxv 20000
#define INF 0x3f3f3f3f 
using namespace std;
int n,m;
int v[maxn+5],c[maxn+5];

int head=1,tail=0;
int f[maxv+5];
struct node{
	int id;
	int val;
	node(){
		
	}
	node(int _id,int _val){
		id=_id;
		val=_val;
	}
}q[maxv+5];


int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	scanf("%d",&m);
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++){
		for(int b=0;b<v[i];b++){
			head=1,tail=0;
			for(int a=0;a*v[i]+b<=m;a++){
				//注意必须先把dp[i-1]入队，再更新dp[i] 
				int now=f[a*v[i]+b]-a;//其实是dp[i-1][a*v[i]+b]， 
				while(head<=tail&&now<=q[tail].val) tail--;
				q[++tail]=node(a,now);
				
				while(head<=tail&&a-q[head].id>c[i]) head++; 
				f[a*v[i]+b]=min(f[a*v[i]+b],q[head].val+a);//k=q[tail]
			}
		}
	}
	printf("%d\n",f[m]);
}

