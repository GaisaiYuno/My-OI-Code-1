#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100
using namespace std;
double a[maxn+5];
double timp[maxn+5]; 
int n;
int cmp(double x,double y){
	return x>y; 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	timp[0]=1;
	for(int i=1;i<=n;i++){
		timp[i]=timp[i-1]*(1-a[i]);
	}
	double ans=a[1],cur;
	for(int i=2;i<=n;i++){
		cur=ans*(1-a[i])+a[i]*timp[i-1];//ǰ���������������i����û�������;���i�����������ǰ����ȫ��û������� 
		if(ans<cur) ans=cur;
		else break;
	}
	printf("%.12f",ans);
}

