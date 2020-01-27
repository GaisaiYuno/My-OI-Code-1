#include<iostream>
#include<cstdio>
#define maxn 40005
#define mod 1000000007
using namespace std;
long long x[maxn],y[maxn];
int R,C,xmin,xmax;
int main(){
	long long ans=0;
	cin>>R>>C>>xmin>>xmax;
	for(int i=2;i<=(R-1);i++) x[i*2]=(R-i)*(i-2+1);
	for(int i=2;i<=(C-1);i++) y[i*2]=(C-i)*(i-2+1);
	for(int i=4;i<=2*(R-1);i++){
		for(int j=4;j<=2*(C-1);j++){
			if(xmin<=i+j&&i+j<=xmax){
				ans+=(x[i]*y[j]*6)%mod;
			}
		}
	}
	cout<<ans%mod<<endl;
	
	
}

/*
�������ٺ��ݾ���ֿ����� 
������ĺ����������پ���Ϊ2*(xmax-xmin) 
distx��[4,2(R-1)]  disty��[4,2(C-1)]
�������ϣ�x����Сֵ�����ֵ֮���Ϊi,��R-i��,�м�ֵ��Ϊ2~i-1,��i-2�ֿ��� 
x[i*2]=(R-i)*(i-2)
y[i*2]=(C-i)*(i-2)

���ݳ˷�ԭ�� ��mint<=i+j<=maxt
              sum+=x[i]*y[j]*A(3,2)
			  ��Ϊx1��x2,x3��y1,y2,y3��ԣ���A��3,2)�ֿ��� 
*/ 
