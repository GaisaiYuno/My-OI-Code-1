#include<iostream>
#define maxn 1005
using namespace std;
int n;
int a,b,c;
int ans[maxn];
void dfs(int deep){
	if(deep>n){
		 ans[deep-1]++;
		 return;
	}
	for(int i=1;i<=n;i++){
		if(!(a&(1<<(i)))&&!(b&(1<<(i+deep)))&&!(c&(1<<(deep-i+n)))){
			a=(1<<(i))|a;
			b=(1<<(i+deep))|b;
			c=(1<<(deep-i+n))|c;
			dfs(deep+1);
		    a=a&(~(1<<i));
		    b=b&(~(1<<(i+deep)));
		    c=c&(~(1<<(deep-i+n)));
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
