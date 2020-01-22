//我相信暴力出奇迹
#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 31
#define mo 2017
using namespace std;
inline int fread(){
	register int f=1,x=0;
	register char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int F[maxn];
int G[maxn];
int a[101],b[101];
int main(){
	freopen("cola.in","r",stdin);
	freopen("cola.out","w",stdout);
	register int n=fread(),m=fread();
	for(register int i=1;i<=m;i++){
		a[i]=fread(),b[i]=fread();
	}
	register int t=fread();
	F[1]=1;
	register int ans=0;
	while(t--){
		for(register int i=1;i<=n;i++) ans+=F[i];
		memcpy(G,F,sizeof(F));
		ans%=mo;
		for(register int i=1;i<=m;i++){
			F[a[i]]+=G[b[i]];
			F[b[i]]+=G[a[i]];
		}
		for(register int i=1;i<=n;i++){
			F[i]%=mo;
		}
	}
	for(register int i=1;i<=n;i++) ans+=F[i];
	ans%=mo;
	printf("%d\n",ans);
}
