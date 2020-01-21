//洛谷 属牛的抗议 1569
#include<iostream>
#define maxn 1005
using namespace std;
int a[maxn];
int sum[maxn];
int f[maxn];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    sum[i]=sum[i-1]+a[i]; 
	    if(sum[i]>=0) f[i]=1;
	} 
    for(int i=1;i<=n;i++){
    	for(int j=1;j<i;j++){
    		if(sum[i]-sum[j]>=0&&f[j]>0) f[i]=max(f[i],f[j]+1);
		}
	}
	if(f[n]>0) cout<<f[n]<<endl;
	else cout<<"Impossible"<<endl;
	return 0;
} 
/*状态转移方程
   f(i)=max{f(k)+1，f(i)} (1<=k<i, f(k)>0 , sum[i]-sum[j]>=0)
*/ 
