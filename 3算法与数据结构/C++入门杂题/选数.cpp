#include<iostream>
#define maxn 100000
using namespace std;
int a[maxn],used[maxn];
int ans=0,n,k;
int is_prime(int x){
	if(x==1||x==0) return 0;
	if(x%2==0&&x!=2) return 0;
	for(int i=3;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}
void dfs(int sum,int l,int r){//现在选了l个数，还剩 r个数 
    if (n-l<r)
        return;
    if(r==0){
    	if(is_prime(sum))ans++;
    	return;
	}
    dfs(sum+a[l],l+1,r-1);
    dfs(sum,l+1,r);
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	dfs(0,0,k);
	cout<<ans;
	return 0;
} 
