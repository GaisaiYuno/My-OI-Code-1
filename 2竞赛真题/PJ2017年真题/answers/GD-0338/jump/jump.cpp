#include<cstdio>
#include<string.h>
int a[500005][2];
long long s[500005];
bool pi[500005];
int n,d,k,p,q;
long long ans;
int max(long long  x,long long y){
	if (x>y) return x;
	else return y;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	p=0; q=a[n][0]-d;
	while (p<=q){
		memset(pi,0,sizeof(pi));
		int g=(p+q)/2;
		pi[0]=1;
		ans=0;
		s[0]=0;
		for (int i=0;i<=n;i++)
		if (pi[i]){
			if (s[i]>ans) ans=s[i];
			int j=i+1;
			while (j<=n&&a[j][0]-a[i][0]<=g+d){
				if (a[j][0]-a[i][0]>=d-g){
					if (pi[j]){
						long long e=s[i]+a[j][1];
						s[j]=max(s[j],e);
					}
					else{
						s[j]=s[i]+a[j][1];
						pi[j]=1;
					}
				}
				j++;
			}	
		}
		if (ans>=k) q=g-1;
		else p=g+1;
	}
	if (p>a[n][0]-d) printf("-1\n");
	else printf("%d\n",p);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
