#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200005
#define maxlog 32
#define maxv 1000005
using namespace std;
int n;
int a[maxn];
int b[maxv];
int st[maxv][maxlog];
int ma;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
} 
void st_init(){
	for(int i=1;i<=ma;i++){
		st[i][0]=b[i];
	}
	for(int j=1;(1<<j)<=ma;j++){
		for(int i=1;i+(1<<(j-1))<=ma;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}

int log2(int x) {
  int cnt = -1; 
  while(x) {
    x >>= 1; 
    cnt++; 
  }
  return cnt; 
}
int st_query(int l,int r){
	if(l>r) return 0;
	if(r>ma) r=ma;
	int t=log2(r-l+1);	
	return max(st[l][t],st[r-(1<<t)+1][t]);
}
int work2(){
	int id=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(long long k=2;;k++){
			ans=max(ans,st_query(a[i],k*a[i]-1)%a[i]);
			if(k*a[i]>a[n]) break;
		}
	}
	return ans;
}
int main(){
//	freopen("max.in","r",stdin);
//	freopen("max.out","w",stdout);
//	scanf("%d",&n);
	n=qread();
	for(int i=1;i<=n;i++){
//		scanf("%d",&a[i]);
		a[i]=qread();
		ma=max(ma,a[i]);
		b[a[i]]=a[i];
	}
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	st_init();
	int ans=work2();
	printf("%d\n",ans);
}
