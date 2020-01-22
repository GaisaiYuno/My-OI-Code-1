#include<bits/stdc++.h>
using namespace std;
int n,d,k,mn,mx,i,x[100010],s[100010],ss[200010],f[200010],g,mn1,mx1,j,vis[200010];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	mn1=100001;
	mx1=-100001;
	for(i=1;i<=n;i++){
	  scanf("%d%d",&x[i],&s[i]);
	  ss[x[i]+100000]=s[i];
	  if(s[i]>0) mx+=s[i];
	  mn1=min(mn1,x[i]);
	  mx1=max(mx1,x[i]);
	  vis[x[i]+100000]=1;
	}
	if(mx<k){
		cout<<-1;
		return 0;
	}
	for(g=2;g<=n;g++){
		memset(f,0,sizeof(f));
		mn=max(d-g,1);
		mx=d+g;
		for(i=mn1-mn;i<=mx1-mx;i++){
			for(j=mn;j<=mx;j++)
			if(vis[i+100000+j]==1&&vis[i+100000]==1){
			  f[i+100000+j]=max(f[i+100000+j],f[i+100000]+ss[i+100000+j]);
			  if(f[i+100000+j]>=k){
			  	printf("%d",g);
			  	return 0;
			  }
			}
		}
	}
}
