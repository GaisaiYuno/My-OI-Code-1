//杭电acm 小蜜蜂 
//递推类型1 
#include<iostream>
#include<cstring>
#define maxn 1000
using namespace std;
int t;
int a,b;
long long f[maxn];
int main() {
	cin>>t;
	for(int j=0; j<t; j++) {
		cin>>a>>b;
		memset(f,0,sizeof(f));
		f[a]=1;
		for(int i=a+1; i<=b; i++) {
            f[i]=f[i-1]+f[i-2];
		}
		cout<<f[b]<<endl;
	}
}
/*递推公式
  f[i]=f[i-1]+f[i-2]
*/
