/*n个人过河,时间为t[i]
桥上每次过拿着手电筒的两个人，时间为两个人的最大时间
需要有人传递手电筒 
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
/*状态转移方程 
f[i]前i个人过去和对面需要的时间消耗 
f[i+1]=min(f[i]+t[1]+t[i+1],f[i+1]) 只剩i+1,1回来，1和i+1过去 
f[i+1]=min(f[i-1]+t[1]+t[i]+t[2]+t[2],f[i+1])   只剩i,i-1,1回来，i和i+1过去,2回来,1和2过去 
综上  f[i+1]=min(f[i]+t[1]+t[i],f[i-1]+t[1]+t[i+1]+t[2]+t[2]) 
*/ 
