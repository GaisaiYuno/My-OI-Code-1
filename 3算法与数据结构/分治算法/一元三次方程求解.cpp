//��p279 ��7.3 
//��� һԪ���η������ 
#include<iostream>
#include<cstdio>
using namespace std;
double x,x1,x2;
double a,b,c,d;
double equa(double x){//������ֵ 
    //if(x==1)cout<<x*x*x*a<<' '<<x*x*b<<' '<<x*c<<' '<<d;
	return x*x*x*a+x*x*b+x*c+d;
}
int main(){
   cin>>a>>b>>c>>d;
   for(x=-100;x<=100;x++){
   	x1=x;
	x2=x+0.99999;
	/*�ǳ���Ҫ�����������⣡
	ԭ����x2=x+1; 
	��x1,x2����������������ֻ���x1,��x2��©�� 
	*/
	if(equa(x1)>-0.00001&&equa(x1)<0.000001) //���Ƿ�Χ������ֱ��д==0 
	     printf("%.2f ",x1);//һ��Ҫ��������λС�� 
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
