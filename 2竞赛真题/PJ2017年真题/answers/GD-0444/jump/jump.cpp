#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,d,k;
ll l,mid,r,x[500005],s[500005],f[500005];
bool flag=false;
bool check(){
	int up=d+mid,down;
	if(mid<d){
		down=d-mid;
	}else{
		down=1;
	}
	f[0]=0;
	ll tmp,ans=0;
	for(int i=1;i<=n;i++){
		tmp=-0x7fffffff;
		for(int j=i-1;j>=0;j--){
			if(x[i]-x[j]<down){
				continue;
			}
			if(x[i]-x[j]>up){
				break;
			}
			tmp=max(tmp,f[j]);
		}
		if(tmp==-0x7fffffff){
			return false;
		}
		f[i]=tmp+s[i];
		if(f[i]>=k){
			flag=true;
			return true;
		}
	}
	return false;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&s[i]);
	}
	r=x[n];
	while(l<r){
		mid=(l+r)/2;
		if(check()){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	if(!flag){
		puts("-1");
	}else{
		printf("%lld\n",l);
	}
	return 0;
}
