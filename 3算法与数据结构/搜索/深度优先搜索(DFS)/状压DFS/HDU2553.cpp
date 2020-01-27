#include<iostream>
#define maxn 1005
using namespace std;
int n;
int a[maxn],b[maxn],c[maxn];
int ans[maxn];
void dfs(int deep){
	if(deep>n){
		 ans[deep-1]++;
		 return;
	}
	for(int i=1;i<=n;i++){
		if(!a[i]&&!b[i+deep]&&!c[deep-i+n-1]){
			a[i]=true;
			b[i+deep]=true;
			c[deep-i+n-1]=true;
			dfs(deep+1);
			a[i]=false;
			b[i+deep]=false;
			c[deep-i+n-1]=false;
		}
	}
}
int main(){
	for(int i=1;i<=10;i++){
		n=i;
		dfs(1);
	}
	while(cin>>n&&n!=0){
		cout<<ans[n]<<endl; 
	}
}
