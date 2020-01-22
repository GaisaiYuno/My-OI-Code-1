#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000 
#define maxlogn 20 
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
			if(se[sa[i-1]]==se[sa[i]]&&se[sa[i-1]+k]==se[sa[i]+k]) rk[sa[i]]=p;
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
		while(str[i+k]==str[j+k]) k++;
		height[rk[i]]=k;
	}
}
struct sparse_table{
	int log2[maxn+5];
	int f[maxn+5][maxlogn+5];
	void ini(int *a,int n){
		memset(f,0x3f,sizeof(f));
		log2[0]=-1;
		for(int i=1;i<=n;i++) log2[i]=log2[i>>1]+1;
		for(int i=1;i<=n;i++) f[i][0]=a[i];
		for(int j=1;(1<<j)<=n;j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int query(int l,int r){
		int k=log2[r-l+1];
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}
}S;
int lcp(int x,int y){
	if(rk[x]>rk[y]) swap(x,y);
	return S.query(rk[x]+1,rk[y]);
}

int T,n,m;
int tot;
char s[maxn+5],t[maxn+5];
bool check(int x){
	int p1=x,p2=n+2,cnt=0;
	while(p2<=tot){
		int len=lcp(p1,p2);
		p1+=len+1;
		p2+=len+1;
		if(p2>tot) break;
		cnt++;
		if(cnt>3) break;
	}
	return cnt<=3;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1); 
		tot=n;
		s[++tot]='|';
		for(int i=1;i<=m;i++) s[++tot]=t[i];
		get_height(s,tot,128);
		S.ini(height,tot);
		int ans=0;
//		check(3);
		for(int i=1;i<=n-m+1;i++){
			if(check(i)) ans++;
		}
		printf("%d\n",ans);
	}
} 
