#include <iostream>  
using namespace std; 
int main () {
float m,a1,b1,c1,a2,b2,c2,k1,k2,x,y,i;
cout<<"������һ����Ԫһ�η�����"<<'\n';
cout<< "a1x+b1y=c1"<<'\n'<<"a2x+b2y=c2"<<'\n';
input:
cout<<"a1=";
cin>>a1;
cout<<"b1=";
cin>>b1;
cout<<"c1=";
cin>>c1;
cout<<"a2=";
cin>>a2;
cout<<"b2=";
cin>>b2;
cout<<"c2=";
cin>>c2;

cout<<"���ڷ�����Ϊ"<<'\n'<<a1<<"x+"<<b1<<"y="<<c1<<'\n'<<a2<<"x+"<<b2<<"y="<<c2<<'\n';
cout<<"��ȷ�Ϸ������Ƿ���ȷ����ȷ�밴1�ⷽ�̣����밴����һλ�������±༭";
cin>>i;
if(i==1){
m=a2/a1;
k1=b2-m*b1;
k2=c2-m*c1;
y=k2/k1;
x=(c1-b1*y)/a1;
cout<<"x="<<x<<'\n'<<"y="<<y<<'\n'<<'\n';
goto input; 
}else{
goto input; 
}
}


