//洛谷 增进感情 2080 
#include<iostream>
#include<cmath>
#define maxn 100
using namespace std;
int n,v;
int a[maxn],b[maxn];
int ans=1000000;
bool flag=false;
void dfs(int h,int x,int y){
	if(h>n){
		int temp=abs(x-y);
		if(x+y>v&&temp<ans){
			ans=temp;
		}
		if(ans==0){
          flag=true;//0则直接输出 
		  //加快速度，否则会TLE 
		}
		return ;
	}  
	if(flag) return;
	dfs(h+1,x,y);
	dfs(h+1,x+a[h],y+b[h]);
} 
int main(){
	cin>>n>>v;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	dfs(1,0,0); 
	if(flag){
		cout<<ans;
		return 0;
	} 
	if(ans!=1000000) cout<<ans;
	else cout<<"-1";
	return 0;
}
