#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define fu(a,b,c) for(register int a=b;a<=c;a++)
#define fd(a,b,c) for(register int a=b;a>=c;a--)
#define ll long long
#define zhh 105
#define mt 1000005
using namespace std;
inline int read(){
	int x=0,f=1;
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
int head[zhh],nt[zhh*2],ver[zhh*2];
int n,m,t,tot;
ll f[mt][35];
void ad1(int x,int y){
	ver[++tot]=y;nt[tot]=head[x];head[x]=tot;
}
void fp(ll x){
	if(x>10) fp(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("cola.in","r",stdin);
	freopen("cola.out","w",stdout);
	n=read(),m=read();
	fu(i,1,m){
		int a=read(),b=read();
		ad1(a,b);
		ad1(b,a);
	}
	t=read();
	fd(i,t,0){
		fu(x,1,n){
			f[i][x]=(f[i+1][x]+1)%2017;
			for(register int j=head[x];j;j=nt[j]){
				int y=ver[j];
				f[i][x]=(f[i][x]+f[i+1][y])%2017;
			}
		}
	}
	fp(f[0][1]);
	return 0;
}
