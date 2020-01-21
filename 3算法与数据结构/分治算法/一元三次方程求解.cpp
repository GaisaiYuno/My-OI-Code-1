//书p279 例7.3 
//洛谷 一元三次方程求解 
#include<iostream>
#include<cstdio>
using namespace std;
double x,x1,x2;
double a,b,c,d;
double equa(double x){//方程求值 
    //if(x==1)cout<<x*x*x*a<<' '<<x*x*b<<' '<<x*c<<' '<<d;
	return x*x*x*a+x*x*b+x*c+d;
}
int main(){
   cin>>a>>b>>c>>d;
   for(x=-100;x<=100;x++){
   	x1=x;
	x2=x+0.99999;
	/*非常重要！书上有问题！
	原来：x2=x+1; 
	若x1,x2正好是两个根，则只输出x1,而x2被漏掉 
	*/
	if(equa(x1)>-0.00001&&equa(x1)<0.000001) //考虑范围，不能直接写==0 
	     printf("%.2f ",x1);//一定要如此输出两位小数 
	else if(equa(x1)*equa(x2)<0){
		while(x2-x1>=0.001){
			double xm=(x2+x1)/2;
			if(equa(x1)*equa(xm)<0) x2=xm;
			else x1=xm; 
		}
		printf("%.2f ",x1);
	}
   }
   return 0;	
}
