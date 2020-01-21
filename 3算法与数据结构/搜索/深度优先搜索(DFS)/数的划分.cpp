#include<iostream>
using namespace std;
int n,k;
int total=0;
int chai[201];
int count;
int wei=0;
void dfs(int x){
	 //1:cout<<wei-1<<' '<<x<<endl;
	if(total==n&&wei==k) count++;	 
	if(total>n) return;
	if(total<n){
		for(int i=x;i<=n;i++){
			//2:
			total+=i;
			chai[wei++]=i;
			dfs(i+1);
			//3:
			total-=i;
			wei--;
		}
	}
}
int main(){
  cin>>n>>k;
  count=0;
  dfs(0);
  cout<<count;
  return 0;
}
