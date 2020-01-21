#include<iostream>
#define maxn 1005
using namespace std;
int t,n,v;
struct item{
	int value;
	int size;
}a[maxn];
int f[maxn];
int main(){
	//此处应改为多组输入数据 
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n>>v;
		for(int i=0;i<n;i++) cin>>a[i].value;
		for(int i=0;i<n;i++) cin>>a[i].size;
		for(int i=0;i<n;i++){
			for(int j=v;j>=a[i].size;j--)
			  f[j]=max(f[j],f[j-a[i].size]+a[i].value);
		}
		cout<<f[v]<<endl;
	}
	return 0; 
} 
