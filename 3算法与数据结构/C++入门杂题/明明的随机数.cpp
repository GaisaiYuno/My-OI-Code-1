//洛谷 明明的随机数
#include<iostream>
#include<algorithm>
#define maxn 105
using namespace std;
int a[maxn];
int n,cnt=0;
int main(){
	 std::ios::sync_with_stdio(false); 
	 cin>>n;
     for(int i=0;i<n;i++) cin>>a[i];
	 sort(a,a+n);
	 for(int j=1;j<n;j++) {
	 	if(a[j]==a[j-1]) cnt++; 
	 }
	 cout<<n-cnt<<endl;
	 for(int k=0;k<n;k++){
	 	if(a[k]!=a[k+1]) cout<<a[k]<<' ';
	 }
} 
