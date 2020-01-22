#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n,d,k,x[500001],s[500001],q[500001],dis[500001];
bool vis[500001]={0};
int check(int g){
	memset(vis,0,sizeof(vis));
	memset(dis,-0x7f,sizeof(dis));
	vis[0]=1;dis[0]=0;
	int mn=max(1,d-g),mx=d+g;
	//cout<<mn<<" "<<mx<<endl;
	int h=0,t=1;q[1]=0;
	while(h<t){
		h++;int j=q[h];
		for(int i=j+1;i<=n;i++){
			if(x[i]-x[j]>mx)break;
			if(x[i]-x[j]>=mn&&x[i]-x[j]<=mx){
				dis[i]=max(dis[i],dis[j]+s[i]);
				if(dis[i]>=k)return 1;
				if(!vis[i]){
					vis[i]=1;
					q[++t]=i;
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	x[0]=0,s[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&s[i]);
	}
	int l=0,r=x[n]-d;bool flag=0;
	//cout<<l<<" "<<r<<endl;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			flag=1;
		}
		else l=mid+1;
	}
	if(flag)printf("%d\n",l);
	else printf("-1\n");
	return 0;
	fclose(stdin);
	fclose(stdout);
}
