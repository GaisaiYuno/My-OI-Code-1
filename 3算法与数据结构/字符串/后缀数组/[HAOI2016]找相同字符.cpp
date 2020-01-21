//http://119.29.55.79/problem/41
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 400000
using namespace std;
typedef long long ll;
int n,m,tot;
char a[maxn+5],b[maxn+5],s[maxn+5];
 
void sort(int *ans,int *fi,int *se,int sz,int maxv){
	static int buck[maxn+5];
	for(int i=0;i<=maxv;i++) buck[i]=0;
	for(int i=1;i<=sz;i++) buck[fi[i]]++;
	for(int i=0;i<=maxv;i++) buck[i]+=buck[i-1];
	for(int i=sz;i>=1;i--) ans[buck[fi[se[i]]]--]=se[i]; 
} 
int sa[maxn+5];
int rk[maxn+5];
int height[maxn+5];
void suffix_sort(char *str,int n,int m){
	static int se[maxn+5];
	for(int i=1;i<=n;i++){
		rk[i]=str[i];
		se[i]=i;
	}
	sort(sa,rk,se,n,m);
	for(int k=1;k<=n;k*=2){
		int p=0;
		for(int i=n-k+1;i<=n;i++) se[++p]=i;
		for(int i=1;i<=n;i++){
			if(sa[i]>k) se[++p]=sa[i]-k;
		}
		sort(sa,rk,se,n,m);
		swap(se,rk);
		p=1; 
		rk[sa[1]]=1;
		for(int i=2;i<=n;i++){
			if(se[sa[i-1]]==se[sa[i]]&&se[sa[i-1]+k]==se[sa[i]+k]) rk[sa[i]]=p; 
			else rk[sa[i]]=++p; 
		}
		if(p==n) break;
		m=p;
	}	
} 
void get_height(char *str,int n,int m){
	suffix_sort(str,n,m);
	for(int i=1;i<=n;i++) rk[sa[i]]=i;
	int k=0;
	for(int i=1;i<=n;i++){
		if(k) k--;
		int j=sa[rk[i]-1];
		while(str[i+k]==str[j+k]) k++;
		height[rk[i]]=k;
	}
}

struct node{
	ll a;
	ll b;
	int h;
	node(){
		
	}
	node(ll _a,ll _b,int _h){
		a=_a;
		b=_b;
		h=_h;
	}
	friend bool operator < (node p,node q){
		return p.h<q.h;
	}
	friend node operator + (node p,node q){
		return node(p.a+q.a,p.b+q.b,p.h);
	}
};
int top=0;
node stk[maxn+5];

int main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1),m=strlen(b+1);
	tot=0;
	for(int i=1;i<=n;i++) s[++tot]=a[i];
	s[++tot]='|';
	for(int i=1;i<=n;i++) s[++tot]=b[i];
	get_height(s,tot,128);
	ll ans=0;
	ll cnta=0,cntb=0;
	for(int i=2;i<=tot;i++){
		node now=node(0,0,height[i]);
		if(sa[i-1]<=n) now.a++;
		else if(sa[i-1]>n+1) now.b++; 
		while(top>0&&now<stk[top]){
			cnta-=stk[top].a*stk[top].h;
			cntb-=stk[top].b*stk[top].h;
			now=now+stk[top];
			top--;
		}
		stk[++top]=now;
		cnta+=now.a*now.h;
		cntb+=now.b*now.h;
		if(sa[i]<=n) ans+=cntb;
		else if(sa[i]>n+1) ans+=cnta;
	}
	printf("%lld\n",ans);
} 
