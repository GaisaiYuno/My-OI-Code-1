//洛谷 保护花朵
//洛谷 保护花朵 
#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
long long n,tim,sum;
struct cow{
    int t;
    int d;
}a[maxn];
inline int read(){
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
int comp(cow x,cow y){
    /*double sx=double(x.d)/double(x.t), sy=double(y.d)/double(y.t);
    return sx>sy;此方法会造成精度丢失*/
	return x.d*y.t>y.d*x.t; 
}
int main(){
    //freopen("flower.in","r",stdin);
    //freopen("flower.out","w",stdout);
    n=read();
    tim=sum=0;
    for(int i=1;i<=n;i++){
        a[i].t=read();
		a[i].d=read();
    }
    sort(a+1,a+1+n,comp);
    for (int i=2;i<=n;i++) {
        tim+=a[i-1].t*2;
        sum+=tim*a[i].d;        
    }
    cout<<sum;
    return 0;
} 

