#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 62505
using namespace std;
int t;
int n,p,q;
int s1[maxn];
int s2[maxn];
int pos[maxn];
int a[maxn];
int s[maxn];
int top; 
void init(){
	top=0;
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(pos,0,sizeof(pos));
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
}
int main(){
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		init();
		scanf("%d %d %d",&n,&p,&q);
		for(int i=1;i<=p+1;i++){
			scanf("%d",&s1[i]);
			pos[s1[i]]=i; 
		} 
		n=0;
		for(int i=1;i<=q+1;i++){
			scanf("%d",&s2[i]);
			if(pos[s2[i]]!=0) a[++n]=pos[s2[i]];
		} 
		top=0; 
		int tmp;
		for(int i=1;i<=n;i++){
			if(a[i]>s[top]) s[++top]=a[i];
			else{
				tmp=lower_bound(s+1,s+top+1,a[i])-s;
				s[tmp]=a[i];
			}
		} 
		printf("Case %d: %d\n",cas,top);
	}
}
