/*n���˹���,ʱ��Ϊt[i]
����ÿ�ι������ֵ�Ͳ�������ˣ�ʱ��Ϊ�����˵����ʱ��
��Ҫ���˴����ֵ�Ͳ 
*/ 
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 1005
int n;
int t[maxn]; 
int f[maxn];
using namespace std;
int main(){
	while(cin>>n){
		for(int i=1;i<=n;i++) cin>>t[i];
		sort(t+1,t+1+n); 
		f[1]=t[1];
		f[2]=t[2];
		for(int i=2;i<n;i++){
			f[i+1]=min(f[i]+t[1]+t[i+1],f[i-1]+t[1]+t[i+1]+t[2]+t[2]) ;
		} 
		cout<<f[n]<<endl; 
		//for(int i=1;i<=n;i++) cout<<f[i]<<' ';
		//cout<<endl;
	}
}
/*״̬ת�Ʒ��� 
f[i]ǰi���˹�ȥ�Ͷ�����Ҫ��ʱ������ 
f[i+1]=min(f[i]+t[1]+t[i+1],f[i+1]) ֻʣi+1,1������1��i+1��ȥ 
f[i+1]=min(f[i-1]+t[1]+t[i]+t[2]+t[2],f[i+1])   ֻʣi,i-1,1������i��i+1��ȥ,2����,1��2��ȥ 
����  f[i+1]=min(f[i]+t[1]+t[i],f[i-1]+t[1]+t[i+1]+t[2]+t[2]) 
*/ 
