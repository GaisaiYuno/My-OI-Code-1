//��� ��ҩ
#include<iostream>
#define max 10000
using namespace std;
int t,m;
int time[max],value[max];
int f[max];
int x;//f[x]��ʾʱ�䲻����xʱ��value �����ֵ 
int main(){
	cin>>t>>m;
	for(int i=0;i<m;i++){
		cin>>time[i]>>value[i];
	}
	
	for(int j=0;j<m;j++){
		 for(x=t; x>=time[j];x--){
		 	if(f[x-time[j]]+value[j]>f[x]) 
			     f[x]=f[x-time[j]]+value[j];
		 }
	}
	cout<<f[t];
	return 0;
}
/*���ƹ�ʽ
              {f(t,m-1)
   f(t,m) =max{
              {f(t-t[m],m-1)+v[m]
              */
