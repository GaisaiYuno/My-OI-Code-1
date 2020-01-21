//duliu
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxc 100
#define maxl 1000
#define maxS 128
#define maxn (maxc*maxl+maxc) 
using namespace std;
int n;
 
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
//	for(int i=1;i<=n;i++) printf("%d ",sa[i]);
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

char in[maxc+5][maxl+5];
int tot=0; 
char all[maxn+5];
int kind[maxn+5];
int count_str(int l,int r){
	static int vis[maxn+5];
	int ans=0;
	if(kind[sa[l-1]]&&!vis[kind[sa[l-1]]]){
		ans++;
		vis[kind[sa[l-1]]]=1;
	}
	for(int i=l;i<=r;i++){
		if(kind[sa[i]]==0) continue;
		if(!vis[kind[sa[i]]]){
			ans++;
			vis[kind[sa[i]]]=1;
		}
	}
	for(int i=r;i>=l-1;i--){
		if(kind[sa[i]]==0) continue;
		vis[kind[sa[i]]]=0;
	}
	return ans;
}
bool check(int mid){
	int l=1,r=1;
	for(int i=1;i<=tot;i++){
		if((i==1||height[i-1]<mid)&&height[i]>=mid)l=i;
		if((i==n||height[i+1]<mid)&&height[i]>=mid){
			r=i;
			if(count_str(l,r)*2>n) return 1;
		}
	}
	return 0;
}


void print(int mid){
	int l=1,r=1;
	for(int i=1;i<=tot;i++){
		if((i==1||height[i-1]<mid)&&height[i]>=mid)l=i;
		if((i==n||height[i+1]<mid)&&height[i]>=mid){
			r=i;
			if(count_str(l,r)*2>n){
				for(int j=sa[r];j<sa[r]+mid;j++) putchar(all[j]);
				putchar('\n'); 
			} 
		}
	}
}

void ini(){
	tot=0;
	for(int i=1;i<=n;i++) height[i]=sa[i]=rk[i]=0;
} 
int main(){ 
	while(scanf("%d",&n)!=EOF&&n!=0){ 
		ini();
		int l=0,r=0;
		for(int i=1;i<=n;i++){
			scanf("%s",in[i]+1);
			int len=strlen(in[i]+1);
			for(int j=1;j<=len;j++){
				tot++;
				all[tot]=in[i][j];
				kind[tot]=i;
			}
			tot++;
			all[tot]='|';
			kind[tot]=0;
			r=max(r,len);
		}
//		printf("%s\n",all+1); 
		get_height(all,tot,maxS);
		int mid,ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}else r=mid-1;
		}
//		printf("%d\n",ans);
		if(ans==0) puts("?");
		else print(ans); 
	} 
}
