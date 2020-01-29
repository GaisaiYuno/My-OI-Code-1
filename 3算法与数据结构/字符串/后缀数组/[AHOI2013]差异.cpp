//https://www.luogu.com.cn/problem/P4248
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<stack>
#define maxn 500000
#define maxs 128
using namespace std;
typedef long long ll;
void rsort(int *ans,int *fi,int *se,int n,int m){
	static int buck[maxn+5];
	for(int i=0;i<=m;i++) buck[i]=0;
	for(int i=1;i<=n;i++) buck[fi[i]]++;
	for(int i=1;i<=m;i++) buck[i]+=buck[i-1];
	for(int i=n;i>=1;i--) ans[buck[fi[se[i]]]--]=se[i];
}
int sa[maxn+5],rk[maxn+5],height[maxn+5];
void suffix_sort(char *s,int n,int m){
	static int se[maxn+5];
	for(int i=1;i<=n;i++){
		rk[i]=s[i];
		se[i]=i;
	}
	rsort(sa,rk,se,n,m);
	for(int k=1;k<=n;k*=2){
		int p=0;
		for(int i=n-k+1;i<=n;i++) se[++p]=i;
		for(int i=1;i<=n;i++) if(sa[i]>k) se[++p]=sa[i]-k;
		rsort(sa,rk,se,n,m);
		swap(rk,se);
		rk[sa[1]]=1;
		p=1;
		for(int i=2;i<=n;i++){
			if(se[sa[i-1]]==se[sa[i]]&&se[sa[i-1]+k]==se[sa[i]+k]) rk[sa[i]]=p;
			else rk[sa[i]]=++p;
		}
		if(p==n) break;
		m=p;
	}
}
void get_height(char *s,int n,int m){
	suffix_sort(s,n,m); 
	for(int i=1;i<=n;i++) rk[sa[i]]=i;
	int k=0;
	for(int i=1;i<=n;i++){
		if(k) k--;
		int j=sa[rk[i]-1];
		while(s[i+k]==s[j+k]) k++;
		height[rk[i]]=k;
	}
}

int n;
char in[maxn+5];

int lb[maxn+5],rb[maxn+5];
void mono_stack(){
	stack<int>s;
	for(int i=1;i<=n;i++){
		while(!s.empty()&&height[s.top()]>height[i]){
			rb[s.top()]=i;
			s.pop(); 
		}
		if(!s.empty()) lb[i]=s.top();
		else lb[i]=0;
		s.push(i);
	}
	while(!s.empty()){
		rb[s.top()]=n+1;
		s.pop();
	}
}

int main(){
	scanf("%s",in+1);
	n=strlen(in+1);
	get_height(in,n,maxs);
	mono_stack();
	ll ans=1ll*(n-1)*n*(n+1)/2;
	for(int i=2;i<=n;i++){
		ans-=2ll*(i-lb[i])*(rb[i]-i)*height[i];
	}
	printf("%lld\n",ans);
}

