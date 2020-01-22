#include<iostream>
#include<cstdio>

using namespace std;

int n,d,k,s[500001],f[500001],x[500001],sum;

int lbd(int y){
	int l=0,r=n,m;
	while(l<r){
		m=(l+r)/2;
		if(x[m]>=y)r=m;
		else l=m+1;
	}
	return l;
}

int ubd(int y){
	int l=0,r=n,m;
	while(l<r){
		m=(l+r)/2;
		if(x[m]<y)l=m+1;
		else r=m;
	}
	return r;
}

int dp(int d1,int d2){
	int maxn=-100000001;
	for(int i=1;i<=n;++i)f[i]=-100000001;
	for(int i=1;i<=n;++i){
		for(int j=lbd(x[i]-d1);j<=ubd(x[i]-d2);++j)f[i]=max(f[i],f[j]+s[j]);
		maxn=max(maxn,f[i]);
	}
//	printf("dp(%d,%d) return %d\n",d1,d2,maxn);
	return maxn;
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&x[i],&s[i]);
		if(s[i]>0)sum+=s[i];
	}
//	for(int i=1;i<=n;++i)printf("%d ",x[i]);
//	puts("");
//	for(int i=1;i<=x[n];++i)printf("%d %d,%d\n",i,lbd(i),ubd(i));
	if(sum<k){
		puts("-1");
		return 0;
	}
	int l=1,r=500000,g;
	while(l+1<r){
		g=(l+r)/2;
//		printf(" DIV %d,%d,%d\n",l,r,g);
		if(dp(max(1,d-g),d+g)>=k)r=g;
		else l=g;
	}
	printf("%d",g);
}
