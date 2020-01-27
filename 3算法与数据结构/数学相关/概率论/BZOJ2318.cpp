#include<iostream>
#include<cstdio>
#define maxn 1005
using namespace std;
int t,n;
double p,q;
double f[maxn+5],g[maxn+5];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		n=min(n,1000);
		scanf("%lf %lf",&p,&q);
		f[0]=0;
		g[0]=1;//没有石子的时候到b投，那么a取到最后一颗
		for(int i=1;i<=n;i++){
			double x,y;
			if(f[i-1]>g[i-1]){//如果剩i-1颗时b投概率较小，那么a不取，想要反面 
				x=1-p;
				y=1-q;
			}else{
				x=p;
				y=q;
			} 
			f[i]=(x*g[i-1]+(1-x)*y*f[i-1])/(1-(1-x)*(1-y));
            g[i]=(y*f[i-1]+(1-y)*x*g[i-1])/(1-(1-x)*(1-y));
		} 
		printf("%.6f\n",f[n]); 
	}
}

