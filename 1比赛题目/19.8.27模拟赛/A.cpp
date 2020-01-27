#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000 
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
int a[maxn+5];

int b[maxn+5],c[maxn+5];
int sum[maxn+5];
int cnt[maxn+5],cnt2[maxn+5];
int solve(){
	int dn;
	for(int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+1+n);
	dn=unique(b+1,b+1+n)-b-1;
	
	for(int i=1;i<=n;i++) cnt[i]=0;
	for(int i=1;i<=n;i++) cnt[a[i]]++;
	for(int i=1;i<=dn;i++){
		sum[i]=sum[i-1]+cnt[a[dn]];
	}
	for(int i=dn;i>=1;i--){
		if(b[i]-cnt[b[i]]!=b[i-1]){
			int last=cnt[b[i]];
			cnt[b[i]]=b[i]-b[i-1];
			cnt[b[i-1]]+=last-cnt[b[i]];
		}
	}
	
	int sz=0;
	for(int i=0;i<=dn;i++){
		for(int j=1;j<=cnt[b[i]];j++){
			c[++sz]=b[i];
		}
	}
//	for(int i=1;i<=sz;i++){
//		printf("%d ",c[i]);
//	} 	
	int ans=0;
	for(int i=1;i<=n;i++) cnt2[i]=0;
	for(int i=1;i<=sz;i++) cnt2[a[i]]++;
	for(int i=1;i<=sz;i++){
		ans+=cnt[c[i]]-cnt2[c[i]]; 
	}
	return ans;
}
int main(){
	freopen("1.in","r",stdin); 
	int x,y;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(a[i]);
	}
	for(int i=1;i<=m;i++){
		qread(x);
		qread(y);
		a[x]=y;
		qprint(solve());
		putchar('\n');
	}
}
