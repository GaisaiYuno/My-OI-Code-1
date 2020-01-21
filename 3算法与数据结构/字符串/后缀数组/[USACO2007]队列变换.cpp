
//http://119.29.55.79/problem/620 
//https://www.luogu.com.cn/problem/P2870 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 30000
#define maxs 128 
using namespace std;
int n;
char s[maxn*2+5];
char t[maxn*2+5];

void rsort(int *ans,int *fi,int *se,int sz,int maxv){
	static int buck[maxn*2+5];
	for(int i=0;i<=maxv;i++) buck[i]=0;
	for(int i=1;i<=sz;i++) buck[fi[i]]++;
	for(int i=1;i<=maxv;i++) buck[i]+=buck[i-1];
	for(int i=sz;i>=1;i--) ans[buck[fi[se[i]]]--]=se[i];
}
int sa[maxn*2+5],rk[maxn*2+5],height[maxn*2+5];
void suffix_sort(char *str,int n){
	static int se[maxn*2+5];
	for(int i=1;i<=n;i++){
		rk[i]=str[i];
		se[i]=i;
	}
	rsort(sa,rk,se,n,maxs);
	for(int k=1,m=maxs;k<=n;k*=2){
		int p=0;
		for(int i=n-k+1;i<=n;i++) se[++p]=i;
		for(int i=1;i<=n;i++){
			if(sa[i]>k) se[++p]=sa[i]-k;
		}
		rsort(sa,rk,se,n,m);
		swap(rk,se);
		p=rk[sa[1]]=1;
		for(int i=2;i<=n;i++){
			if(se[sa[i-1]]==se[sa[i]]&&se[sa[i-1]+k]==se[sa[i]+k]) rk[sa[i]]=p;
			else rk[sa[i]]=++p;
		}
		if(p==n) break;
		m=p;
	}
}



bool cmp(int l,int r){
	if(s[l]<s[r]) return 0;
	else if(s[l]>s[r]) return 1;
	else{
		if(rk[l]<=rk[n*2-r+1]) return 0;
		else return 1;  
	}
	
}

char ans[maxn+5]; 
int main(){
	char ch[10];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",ch);
		s[i]=ch[0];
	}
	for(int i=1;i<=n;i++) t[i]=s[i];
	for(int i=1;i<=n;i++) t[n+i]=s[n-i+1];
//	get_height(t,n);
	suffix_sort(t,n*2);
	int l=1,r=n;
	int sz=0;
	while(l<=r){
		if(cmp(l,r)) ans[++sz]=s[r--];
		else ans[++sz]=s[l++];
	} 
	for(int i=1;i<=sz;i++){
		putchar(ans[i]);
		if(i%80==0) putchar('\n');
	}
} 
