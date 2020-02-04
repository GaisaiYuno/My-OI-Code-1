//http://119.29.55.79/problem/1926 
#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 100000
using namespace std;
typedef long double db;
int n;
db m;
db a[maxn+5],b[maxn+5],c[maxn+5];
db x[maxn+5];
db f(int i,db x){
	return a[i]*x*x+b[i]*x+c[i];
}
int main(){
	scanf("%d %LF",&n,&m);
	for(int i=1;i<=n;i++) scanf("%Lf %Lf %Lf",&a[i],&b[i],&c[i]);
	//f'(x1)=f'(x2)=....=f'(xn) f'(x)=2ax+b 
	//把x[i]用x[n]表示,求出系数
	//然后代入x[1]+x[2]+...x[n]=m,解出x[n]
	//反过来求出x[i]
	db sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		sum1+=a[n]/a[i];
		sum2+=(b[n]-b[i])/(2*a[i]);
	} 
	x[n]=(m-sum2)/sum1;
	db ans=0;
	for(int i=1;i<=n;i++){
		x[i]=a[n]/a[i]*x[n]+(b[n]-b[i])/(2*a[i]);
		ans+=f(i,x[i]);
	}
	printf("%.3Lf\n",ans);
}

