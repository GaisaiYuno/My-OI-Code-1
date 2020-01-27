#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500000
using namespace std;
int t,n;
char str[maxn+5];
int a[maxn+5];
struct node{
	int val;
	int id;
	node(){
		
	}
	node(int _val,int _id){
		val=_val;
		id=_id;
	}
}s[maxn+5];
int lb[maxn+5],rb[maxn+5];
int top=0;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",str+1);
		n=strlen(str+1);
		for(int i=1;i<=n;i++) a[i]=str[i]-'0';
		top=0;
		for(int i=1;i<=n;i++){
			while(s[top].val>a[i]&&top>0){
				rb[s[top].id]=i-1;
				top--;
			}
			s[++top]=node(a[i],i);
		}
		while(top>0){
			rb[s[top].id]=n;
			top--;
		}
		top=0;
		for(int i=n;i>=1;i--){
			while(s[top].val>=a[i]&&top>0){
				lb[s[top].id]=i+1;
				top--;
			}
			s[++top]=node(a[i],i);
		}
		while(top>0){
			lb[s[top].id]=1;
			top--;
		}
		long long ans=0;
//		for(int i=1;i<=n;i++) printf("i=%d [%d,%d]\n",i,lb[i],rb[i]);
		for(int i=1;i<=n;i++){
			ans+=1ll*a[i]*(i-lb[i]+1)*(rb[i]-i+1); 
		}
		printf("%lld\n",ans);
	}
}

