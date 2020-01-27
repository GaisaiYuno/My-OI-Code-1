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
int work2(){
	int id=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=2;;j++){
			int v=j*a[i]; 
			int id=lower_bound(a+i,a+1+n,v)-a;
			ans=max(ans,a[id-1]%a[i]);
			if(v>ma) break;
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
	int ans=work2();
	printf("%d\n",ans);
}
