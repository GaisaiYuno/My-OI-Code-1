//洛谷 疯狂的采药
#include<iostream>
#define max 1000001
using namespace std;
int t,m;
int time[max],value[max],f[max];
int x;
int main(){
    cin>>t>>m;
    for(int i=0;i<m;i++){
		cin>>time[i]>>value[i];
	}
	for(int j=0;j<m;j++){
		for(int i=time[j];i<=t;i++){
			if(f[i-time[j]]+value[j]>f[i]){
				f[i]=f[i-time[j]]+value[j];
			}
		}

	}
	cout<<f[t];
	return 0;
}
/*递推公式
              {f(t,m-1)
   f(t,m) =max{                        
              {f(t-n*t[m],m-1)+n*v[m](n<=t/t[m]
*/
