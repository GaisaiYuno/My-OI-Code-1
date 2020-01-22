#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,d,m,check,a[500010],b[500010],f[500010];
int dfs(int k,int g,int now,int wh){
	if(now+b[k]>=m)
		return 1;
	if(k==n)
		return 0;
	for(int i=k+1;i<=n;i++)
		if(a[i]-wh+1<=d+g&&a[i]-wh+1>=max(d-g,1)){
			if(f[a[i]-wh+1]==-1)
				f[a[i]-wh+1]=dfs(i,g,now+b[i],a[i]);
			if(f[a[i]-wh+1])
				return 1;
		}
	return 0;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]),check+=b[i]>0?b[i]:0;
	if(check<m){
		puts("-1");
		return 0;
	}
	int l=0,r=a[n]-d;
	while(l<r){
		int mid=(l+r)>>1;
		memset(f,-1,sizeof(f));
		dfs(0,mid,0,1)?r=mid:l=mid+1;
	}
	printf("%d",r);
	return 0;
}
