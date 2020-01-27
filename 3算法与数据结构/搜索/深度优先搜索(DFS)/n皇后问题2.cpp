#include<iostream>
#define maxn 15
using namespace std;
int ans=0;
int c[maxn];
int n;
void dfs(int cur){
	if(cur==n) ans++;
	else {
		for(int i=0;i<n;i++){
			bool ok=true;
			c[cur]=i;
			for(int j=0;j<cur;j++){
				if(c[cur]==c[j]||c[cur]-c[j]==cur-j||c[cur]-c[j]==-(cur-j)){
					ok=false;
					break;
				}
			}
			if(ok) dfs(cur+1);
		}
	}
}
int main(){
	cin>>n;
	dfs(0);
	cout<<ans;
} 
