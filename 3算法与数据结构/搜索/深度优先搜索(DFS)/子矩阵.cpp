//洛谷 子矩阵 2258
#include<iostream>
#include<cmath>
#include<cstring> 
#define maxn 1000
using namespace std;
int m,n,r,c;
int a[maxn][maxn];
int used_h[maxn],used_l[maxn];
int ans=100000;
int value(int s,int e){
    int sum=0;//s行e列 
	for(int i=s;i<r+s;i++){
		for(int j=e;j<c+e;j++){
			sum+=abs(a[i][j]-a[i][j+1]);
			sum+=abs(a[i][j]-a[i+1][j]); 
		}
	}
	return sum;
}
void dfs_l(int deep,int h,int l){//算列 
	if(deep==c){
		value(h,l);
		return;
	}
	else{
		for(int i=0;i<n;i++){
			if(used_l[i]==0){
				used_l[i]=1;
				dfs_l(deep+1,i,h);
				used_l[i]=0;
			} 
		}
	}
}
void dfs_h(int deep,int h,int l){//算行  
	if(deep==r){
		cout<<h<<' '<<l<<endl;
		return; 
	}
	else{
		for(int i=0;i<m;i++){
			if(used_h[i]==0){
				used_h[i]=1;
				dfs_h(deep+1,i,0);
				used_h[i]=0;
			} 
		}
	}
}
int main(){
    cin>>m>>n>>r>>c;
    for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++) cin>>a[i][j];
	}
    dfs_h(1,0,0);
	cout<<ans;
	return 0;
}
