#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

struct point{int w,x;}p[500001];

int n,d,k,sum1,f[500001];

bool cmp(point x,point y){return x.w<y.w;}

bool check(int x){
	memset(f,0,sizeof(f));
	int re=0;
	for(int i=1;i<=n;i++){
		f[i]=p[i].x;
		int j=i,maxn=-0x7fffffff;
		while(j>0&&p[i].w-p[j-1].w<=d+x){
			j--;
			if(p[i].w-p[j].w>=d-x)maxn=max(maxn,f[j]);
		}
		if(j==i)break;
		if(maxn==-0x7fffffff)break;
		f[i]=f[i]+maxn;
		re=max(re,f[i]);if(re>=k)return true;
	}
	return re>=k;
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	p[0].w=p[0].x=0;
	for(int i=1;i<=n;i++){scanf("%d%d",&p[i].w,&p[i].x);if(p[i].x>0)sum1=sum1+p[i].x;}
	sort(p+1,p+1+n,cmp);
	if(sum1<k){printf("-1\n");return 0;}
	int l=0,r=1000000001;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid))r=mid;else l=mid+1;
	}
	printf("%d\n",r!=1000000001?r:-1);
}
