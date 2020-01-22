#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int n,d,k,l=0,r,sum=0;
int x[500005],s[500005];
int f[500005];

bool check(int g){
	if(x[1]<d-g||x[1]>d+g)return false;
	memset(f,0x80,sizeof(f));
	f[1]=s[1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(x[i]-x[j]<d-g)break;
			if(x[i]-x[j]>d+g)continue;
			f[i]=max((long long)f[i],(long long)f[j]+s[i]);
			if(f[i]>=k)return true;
		}
	}
	return false;
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",x+i,s+i);
		if(s[i]>0)sum+=s[i];
	}
	if(sum<k){
		printf("-1");
		return 0;
	}
	l=0,r=1000000000;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d",r);
	return 0;
}
