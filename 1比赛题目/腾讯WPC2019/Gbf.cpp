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
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int minv=10;
				for(int k=i;k<=j;k++){
					minv=min(minv,a[k]);
				}
				ans+=minv;
			} 
		}
		printf("%lld\n",ans); 
	}
}


