//Âå¹È Õ» 1044 
#include<iostream>
#define maxn 100
using namespace std;
int n;
long long int f[maxn];
int main(){
	cin>>n;
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i;j++){
			f[i]=f[i]+f[j]*f[i-j-1];
		}
	}
	cout<<f[n];
} 
/*µÝÍÆ¹«Ê½
           n
	  f(n)=¡Æf(k-1)*f(n-k) 
	      k=1
	=f(0)*f(n-1)+f(1)*f(n-2)+¡­¡­+f(n-1)*f(0) 
*/
 
