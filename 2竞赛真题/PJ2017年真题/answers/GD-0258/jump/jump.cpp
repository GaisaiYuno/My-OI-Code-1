#include<bits/stdc++.h>
using namespace std;
	int n,d,k,dis[51000],x[510000],s[510000],l,r,mid,sum=0; bool bo=true;
int ef1(int num){
	int l=1,r=n,mid;
	while(l!=r){
		mid=(l+r)/2;
		if(x[mid]<num)l=mid+1; else r=mid;
	}
	return l;
}
int ef2(int num){
	int l=1,r=n,mid;
	while(l!=r){
		mid=(l+r)/2;
		if(x[mid]<num)l=mid+1; else r=mid;
	}
	return l;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k); 
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&s[i]); if(s[i]>0)sum+=s[i]; 
	}
	if(sum<k){
		printf("-1"); return 0;
	}
	l=0; r=max(d-1,x[n]-d); 
	while(l!=r){
		mid=(l+r)/2; 
		for(int i=1;i<=n;i++)dis[i]=-INT_MAX;
		if(mid<d){
			dis[1]=s[1];
			for(int i=1;i<=n-1;i++)
			for(int j=ef1(x[i]+mid-d);j<=ef2(s[i]+mid+d);j++)
			if(x[i]+d-mid<=x[j]&&x[i]+d+mid>=x[j])
			dis[j]=max(dis[i]+s[j],dis[j]);
			if(dis[n]>=k)r=mid; else l=mid+1;
		}
		if(mid>=d){
			dis[1]=s[1];
			for(int i=1;i<=n;i++)for(int j=i+1;j<=ef2(x[i]+d+mid);j++)if(x[i]+d+mid>=x[j])dis[j]=max(dis[j],dis[i]+s[j]);
			if(dis[n]>=k)r=mid; else l=mid+1;
		}
		//if(dis[n]!=-INT_MAX)bo=false;
	}
	printf("%d",mid);
}
