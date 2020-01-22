#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
#define zhh 100005
using namespace std;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll n,k,tot;
//ll m[zhh];
int f[zhh][25];
int head[zhh],nt[zhh*2],ver[zhh*2];
void ad1(int x,int y){
	ver[++tot]=y;nt[tot]=head[x];head[x]=tot;
}
//void dfs(int x,int pr,int p,int zz){
//	
//	for(int i=head[x];i;i=nt[i]){
//		int y=ver[i];
//		if(y==pr) continue;
//		if(p==0) continue;
//		m[y]+=zz;
//		dfs(y,x,p-1,zz);
//	}
//}
void fp(int x){
	if(x>=10) fp(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("nearcows.in","r",stdin);
	freopen("nearcows.out","w",stdout);
	n=read(),k=read();
	fu(i,1,n-1){
		int u=read(),v=read();
		ad1(u,v);
		ad1(v,u);
	}
	fu(i,1,n){
		f[i][0]=read();
	}
	fu(j,1,k){
		fu(i,1,n){
			if(j==1){
				f[i][j]=f[i][j-1];
			}
			else{
				f[i][j]=f[i][j-2];
			}
			for(int l=head[i];l;l=nt[l]){
    			int y=ver[l];
    			f[i][j]+=f[y][j-1];
    			if(j>=2){
					f[i][j]-=f[i][j-2];
				}
			}
		}
	}
	fu(i,1,n){
		fp(f[i][k]);
		puts("");
	}
	return 0;
}
