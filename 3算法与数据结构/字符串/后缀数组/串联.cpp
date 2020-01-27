//http://119.29.55.79/problem/3278
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
#define maxs 128
#define maxlogn 25
using namespace std;



int sa[maxn+5],rk[maxn+5],height[maxn+5],se[maxn+5],buck[maxn+5];
void suffix_sort(char *str,int n){
//	memset(sa,0,sizeof(sa));
//	memset(rk,0,sizeof(rk));
//	memset(height,0,sizeof(height));
	register int i,k,p,m;
	for(i=1;i<=n;i++) sa[i]=rk[i]=0;
	int* _se=se;
	int* _rk=rk;
	for(i=1;i<=n;i++){
		_rk[i]=str[i];
		_se[i]=i;
	}
	for(i=0;i<=maxs;i++) buck[i]=0;
	for(i=1;i<=n;i++) buck[_rk[i]]++;
	for(i=0;i<=maxs;i++) buck[i]+=buck[i-1];
	for(i=n;i>=1;i--) sa[buck[_rk[_se[i]]]--]=_se[i];
	for(k=1,m=maxs;k<=n;k*=2){
		p=0;
		for(i=n-k+1;i<=n;i++) _se[++p]=i;
		for(i=1;i<=n;i++){
			if(sa[i]>k) _se[++p]=sa[i]-k;
		} 
		for(i=0;i<=m;i++) buck[i]=0;
		for(i=1;i<=n;i++) buck[_rk[i]]++;
		for(i=0;i<=m;i++) buck[i]+=buck[i-1];
		for(i=n;i>=1;i--) sa[buck[_rk[_se[i]]]--]=_se[i];
		int* tmp=_rk;
		_rk=_se;
		_se=tmp;
		p=_rk[sa[1]]=1;
		for(i=2;i<=n;i++){ 
			if(_se[sa[i-1]]==_se[sa[i]]&&_se[sa[i-1]+k]==_se[sa[i]+k]) _rk[sa[i]]=p;
			else _rk[sa[i]]=++p; 
		}
		if(p==n) break;
		m=p;
	}	
//	for(int i=1;i<=n;i++) printf("%d ",sa[i]);
} 


void get_height(char *str,int n){
	register int i,k;
	for(i=1;i<=n;i++) height[i]=0;
	suffix_sort(str,n);
	for(i=1;i<=n;i++) rk[sa[i]]=i;
	k=0;
	for(i=1;i<=n;i++){
		if(k) k--;
		int j=sa[rk[i]-1];
		while(str[i+k]==str[j+k]) k++;
		height[rk[i]]=k;
	} 
}

//struct sparse_table{
//	int log2[maxn+5];
//	int f[maxn+5][maxlogn+5];
//	void ini(int *a,int n){
////		memset(f,0,sizeof(f)); 
//		log2[0]=-1;
//		for(int i=1;i<=n;i++) log2[i]=log2[i>>1]+1;
//		for(int i=1;i<=n;i++) f[i][0]=a[i];
//		for(int j=1;(1<<j)<=n;j++){
//			for(int i=1;i+(1<<(j-1))-1<=n;i++){
//				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
//			}
//		}
//	}
//	int query(int l,int r){
//		int k=log2[r-l+1];
//		return min(f[l][k],f[r-(1<<k)+1][k]);
//	}
//}ST;
//int lcp(int x,int y){
//	if(rk[x]>rk[y]) swap(x,y);
//	return ST.query(rk[x]+1,rk[y]);
//}

int n;
char s[maxn+5];

int main(){
//	freopen("1.in","r",stdin);
	while(scanf("%s",s+1)!=EOF){ 
		if(s[1]=='.') break;
		n=strlen(s+1);
		get_height(s,n);
//		ST.ini(height,n);
		
		int l=height[rk[1]];
		int len=n;
		for(register int i=rk[1];i>=1;i--){
			if(l==n-sa[i]+1&&n%(sa[i]-1)==0) len=min(len,sa[i]-1);
			l=min(l,height[i]);
		}
		l=n;
		for(register int i=rk[1]+1;i<=n;i++){
			l=min(l,height[i]);
			if(l==n-sa[i]+1&&n%(sa[i]-1)==0) len=min(len,sa[i]-1);
		}
		printf("%d\n",n/len); 
	}
}
