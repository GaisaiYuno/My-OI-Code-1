#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 35
#define maxm 50005
using namespace std;
int n,m;
int a[maxn][maxm];
int l,r;
int sum[maxn][maxm];
int lbound[maxm],rbound[maxm];
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
//	freopen("a2.in","r",stdin);
	char ch;
	n=qread();
	m=qread();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ch=getchar();
			while(ch<'0'||ch>'9') ch=getchar();
			a[i][j]=ch-'0';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			printf("%d",a[i][j]);
			sum[i][j]=sum[i-1][j]+a[i][j];
		}
//		printf("\n");
	}
//	scanf("%d %d",&l,&r);
	l=qread();
	r=qread();
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int tot=sum[j][1]-sum[i-1][1],p=1;
			memset(lbound,0,sizeof(lbound));
			memset(rbound,0,sizeof(rbound));
			for(int k=1;k<=m;k++){
				while(p<=m&&tot<l){
					p++;
					tot+=sum[j][p]-sum[i-1][p];
				}
				if(tot>=l) lbound[k]=max(p,k);
				else break;
				tot-=sum[j][k]-sum[i-1][k];
			}
			tot=0;
			p=0;
			for(int k=1;k<=m;k++){
				while(p<=m&&tot<=r){
					p++;
					tot+=sum[j][p]-sum[i-1][p];
				}
				if(tot>r) rbound[k]=max(p,k);
				else break;
				tot-=sum[j][k]-sum[i-1][k];
			}
			for(int k=1;k<=m;k++){
				if(rbound[k]==0){
					if(lbound[k]!=0) ans+=(long long)m-lbound[k]+1;
					else break;
				}else{
					ans+=(long long)rbound[k]-lbound[k];
				}	
			}
		}
	}
	cout<<ans;
}
