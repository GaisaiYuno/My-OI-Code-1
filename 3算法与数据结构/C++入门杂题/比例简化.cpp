//��� ������ 2118 
#include<iostream>
using namespace std;
int a1,b1,L,a2,b2;
int prime(int x,int y){//�ж��Ƿ��� ,�����Լ�� 
    if(y==0) return x;
    return prime(y,x%y);
}
int main(){
    cin>>a1>>b1>>L;
    int ans1,ans2;
    a2=L;
	b2=1;
    for(int i=1;i<=L;i++){
   	    for(int j=1;j<=L;j++){
   	  	    if(prime(i,j)==1&&i*b1>=j*a1&&i*b2<j*a2) {  //i/j>=a1/b1 ��ԭ��ֵ�� 
   	  		    a2=i;                                   //i/j<a2/b2  
   	  		    b2=j;
	        }
	    } 
    }
    cout<<a2<<' '<<b2;
}
