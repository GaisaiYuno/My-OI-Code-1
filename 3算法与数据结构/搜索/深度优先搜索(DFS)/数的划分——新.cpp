//洛谷 数的划分 
#include<iostream>
using namespace std;
int n,k,ans=0;
void dfs(int n,int last,int step){
	int i;
	if(n>=last&&step==k){
		ans++;
		return;
	}
	if(step==k) return;
	for(int i=last;i<n;i++) dfs(n-i,i,step+1); 
}
int main(){
	cin>>n>>k;
    dfs(n,1,1);
    cout<<ans; 
    return 0;
}
