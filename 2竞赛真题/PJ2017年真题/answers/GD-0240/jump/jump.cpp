#include<bits/stdc++.h>
using namespace std;
int n,d,k,x[550],s[550],ans=0,point;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&s[i]);
	x[0]=0;	s[0]=0;	point=s[0];
	for (int i=1;i<=n;i++){
		ans=max(ans,x[i]-x[i-1]-d);
		point+=s[i];
		if  (point>=k)	{
			printf("%d",ans);
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}
