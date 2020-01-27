#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 255
using namespace std;
inline int fread(){
	register int f=1,x=0;
	char ch=getchar();
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
int main(){
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	register int A[maxn],B[maxn];
	register int n=fread(),w=fread();
	for(register int i=1;i<=n;i++) A[i]=fread(),B[i]=fread();
	register int ans=0;
	for(register int i=0;i<(1<<n);i++){
		register int ww=0,tt=0;
		for(register int j=0;j<n;j++){
			if((i>>j)&1){
				ww+=A[j+1];
				tt+=B[j+1];
			}
		}
		if(ww<w) continue;
		else ans=max(1000*tt/ww,ans);
	}
	printf("%d\n",ans);
}
