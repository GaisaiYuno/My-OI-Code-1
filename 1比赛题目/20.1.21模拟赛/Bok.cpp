#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000 
using namespace std;
void rsort(int *ans,int *fi,int *se,int n,int m){
	static int buck[maxn+5];
	for(int i=0;i<=m;i++) buck[i]=0;
	for(int i=1;i<=n;i++) buck[fi[i]]++;
	for(int i=1;i<=m;i++) buck[i]+=buck[i-1];
	for(int i=n;i>=1;i--) ans[buck[fi[se[i]]]--]=se[i];
}
int sa[maxn+5],rk[maxn+5],height[maxn+5];
void suffix_sort(char *str,int n,int m){
	static int se[maxn+5];
	for(int i=1;i<=n;i++){
		rk[i]=str[i];
		se[i]=i;
	}
	rsort(sa,rk,se,n,m);
	for(int k=1;k<=n;k*=2){
		int p=0;
		for(int i=n-k+1;i<=n;i++) se[++p]=i;
		for(int i=1;i<=n;i++) if(sa[i]>k) se[++p]=sa[i]-k;
		rsort(sa,rk,se,n,m);
		swap(rk,se);
		p=rk[sa[1]]=1;
		for(int i=2;i<=n;i++){
			if(se[sa[i-1]]==se[sa[i-1]+k]&&se[sa[i]]==se[sa[i]+k]) rk[sa[i]]=p;
			else rk[sa[i]]=++p;
		}
		if(p>=n){
			break;
		}
		m=p;
	}
}
void get_height(char *str,int n,int m){
	int k;
	suffix_sort(str,n,m);
	for(int i=1;i<=n;i++) rk[sa[i]]=i;
	k=0;
	for(int i=1;i<=n;i++){
		if(k) k--;
		int j=sa[rk[i]-1];
		int cnt=0;
		while(k<=n){
			if(str[i+k]!=str[j+k]) cnt++;
			if(cnt>3) break;
			k++;
		}
//		printf("%d %d\n",i,k); 
		height[rk[i]]=k;
	}
//	for(int i=1;i<=n;i++) printf("%d ",height[i]); 
}

int T,n,m;
int tot;
char s[maxn+5],t[maxn+5];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1); 
		int tot=n;
		s[++tot]='|';
		for(int i=1;i<=m;i++) s[++tot]=t[i];
		get_height(s,tot,128);
	}
} 
