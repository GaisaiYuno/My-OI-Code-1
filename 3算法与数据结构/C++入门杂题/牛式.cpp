//��� ţʽ
#include<iostream>
#define maxn 9
using namespace std;
int a[maxn];
int check(int x){
	while(x){
		if(a[x%10]==0) return 0;//���ĳһλ���ֲ�����Ŀ�����ģ��򷵻�0 
		else x/=10;//ö����һλ 
	}
	return 1;
}
int main(){
	int n,tmp,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
       a[tmp]=1;//��־��������� 
    }
    for(int j=100;j<=999;j++){
    	for(int k=10;k<=99;k++){
    		if(j*k<=9999&&j*(k%10)<=999&&j*(k/10)<=999) {//λ���ж� 
    			if(check(j)&&check(k)&&check(j*k)&&check(j*(k%10))&&check(j*(k/10))) //�����ж� 
    			            ans++;
			} 
		} 
	}
    cout<<ans;
    return 0;
} 
