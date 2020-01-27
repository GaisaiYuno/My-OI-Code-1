#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100
#define maxv 10000
#define INF 0x3f3f3f3f 
using namespace std;
int n,m;
int v[maxn+5],c[maxn+5];

int head=1,tail=0;
int f[maxv*2+5];
int q[maxn+5];
int calc(int i,int b,int k){
	return f[k*v[i]+b]-k;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	scanf("%d",&m);
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++){
		for(int b=0;b<v[i];b++){
			head=1,tail=0;
			for(int a=(m-b)/v[i];a>=0;a--){
				while(head<=tail&&calc(i,b,a)<=calc(i,b,q[tail])) tail--;
				f[a*v[i]+b]=min(f[a*v[i]+b],calc(i,b,q[tail])+a);//k=q[tail]
				while(head<=tail&&a-q[head]>=c[i]) head++; 
			}
		}
	}
	printf("%d\n",f[m]);
}

