#include<iostream>
using namespace std;
int n,x[26]= {0};
bool used[26]= {0},ans=0;
char s1[26],s2[26],s3[26];
bool ok() {
	bool right=0;
	int m=0;
	for(int i=n-1; i>=0; i--) {
		right=0;
		int sum=x[s1[i]-65]+x[s2[i]-65]+m;
		m=sum/n;
		sum=sum%n;
		if(sum==x[s3[i]-65]) right=1;
		if(!right) break;
	}
	return right;
}
void dfs(int now) {
	if(ans) return;
	if(now==n&&!ok()) return;
	if(now==n&&ok()) {
		ans=1;
		for(int i=0; i<n; i++) cout<<x[i]<<" ";
		return;
	}
	for(int i=n-1; i>=0; i--) {
		if(!used[i]) {
			x[now]=i;
			used[i]=1;
			dfs(now+1);
			used[i]=0;
		}
	}
	return;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n; i++) cin>>s1[i];
	for(int i=0; i<n; i++) cin>>s2[i];
	for(int i=0; i<n; i++) cin>>s3[i];
	dfs(0);
	return 0;
}
