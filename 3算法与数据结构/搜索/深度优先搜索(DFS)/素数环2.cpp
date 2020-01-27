#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 16
using namespace std;
int n;
int a[maxn],is_pri[maxn],used[maxn];
int is_prime(int x){
	if(x==1||x==0) return 0;
	else if(x==2) return 1;
    else if(x%2==0) return 0;
    else{
    	for(int i=3;i*i<=x;i++){
    		if(x%i==0) return 0;
		}
		return 1; 
	}
}
void print_ring(){
	for(int i=0;i<n;i++) cout<<a[i]<<' ';
	cout<<endl;
}
void dfs(int cur){
	if(cur==n&&is_pri[a[n-1]+a[0]]==1) print_ring();
	else{
		for(int i=2;i<=n;i++){
			if(is_pri[a[cur-1]+i]==1&&used[i]==0){
				a[cur]=i;
				used[i]=1;
				dfs(cur+1);
				used[i]=0;
			}
		}
	}
}
int main(){
	for(int i=2;i<=maxn*2;i++) is_pri[i]=is_prime(i);
	int cas=0;
	while(cin>>n){
		memset(used,0,sizeof(used));
		cas++;
		printf("Case %d:\n",cas);
		a[0]=1;
		dfs(1);  
		cout<<endl;
	} 
} 
