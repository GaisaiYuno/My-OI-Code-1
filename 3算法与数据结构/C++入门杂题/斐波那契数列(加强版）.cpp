//��� 쳲��������У���ǿ�棩
#include<iostream>
using namespace std;
int n;
int f[100];
bool flag=false;//����Ƿ�ֽ����� 
void find(int x,int minx){
	if(x<minx) return;
	for(int i=minx;i<=x;i++){
		if(x%i==0){//�ҵ�������������С��
		   if(flag) cout<<'*';
		   else flag=true;
		   cout<<i;
		   find(x/i,i); 
		   return ;
		}
	}
	return; 
}
int main(){
	cin>>n;
	f[1]=1;
	f[2]=1; 
	for(int i=3;i<=n;i++) f[i]=(f[i-1]+f[i-2])%4294967296;
	printf("%d=",f[n]);
	if(n==1||n==2){
		cout<<1;
		return 0;
	}
	find(f[n],2);
	return 0;
} 
