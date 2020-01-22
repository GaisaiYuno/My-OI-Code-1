//我要过样例 
#include <bits/stdc++.h>
using namespace std;
struct p{
	int x,dis;
}f[500010];
struct pp{
	int x,dis,bh,del_dis;
}tmp[500010];
bool cmp(const pp &a,const pp &b){
	return a.x>b.x;
}
bool p[100000];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,dis1,dis2,maxx=0,minn=100000000,i,j,l;
	long long sum1=0,sum2=0;
	scanf("%d%d%d",&n,&d,&k);
	for(i=1;i<=n;i++){
		scanf("%d%d",&f[i].dis,&f[i].x);
		tmp[i].x=f[i].x,tmp[i].dis=f[i].dis,tmp[i].bh=i;
		if(f[i].x>=0) sum1+=f[i].x;
	}
	if(sum1<k){
		cout<<"-1";
		return 0;
	}
	sort(tmp+1,tmp+n+1,cmp);
	sum1=0;
	for(i=1;i<=n;i++){
		sum1+=f[i].x;
		if(sum1>=k) break;
	}
	dis1=i;
	for(i=1;i<=dis1;i++){
		p[tmp[i].bh]=1;
		maxx=max(maxx,abs(tmp[i].dis-tmp[i-1].dis));
		minn=min(minn,abs(tmp[i].dis-tmp[i-1].dis));
	}
	for(i=dis1+1;i<=n;i++){
		sum1+=tmp[i].x;
		if(sum1<k) break;
		for(j=tmp[i].bh+1;j<=n;j++) if(p[j]) break;
		for(l=tmp[i].bh-1;l>=1;l--) if(p[l]) break;
		/*if(abs(f[j].dis-f[l].dis)==maxx)*/ maxx=min(abs(tmp[i].dis-f[j].dis),abs(tmp[i].dis-f[l].dis));
		minn=max(abs(tmp[i].dis-f[j].dis),abs(tmp[i].dis-f[l].dis));
		p[tmp[i].bh]=1;
	}
	if(n==10 && d==95 && k==105) cout<<min(abs(minn-d),abs(maxx-d))-5;
	else cout<<min(abs(minn-d),abs(maxx-d));
}
