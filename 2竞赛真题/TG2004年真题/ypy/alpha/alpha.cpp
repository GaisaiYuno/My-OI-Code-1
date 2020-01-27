#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
int n;
char s1[30],s2[30],s3[30];
int x[30];
int used[30];
bool flag=false;
int is_ok() {
	int jw=0;
	for(int i=n-1;i>=0;i--){
		int sum=x[s1[i]-'A']+x[s2[i]-'A']+jw;
		jw=sum/n;
		sum%=n;
		if(sum!=x[s3[i]-'A'])return 0;
	}
	return 1;
}
void dfs(int now) {
	if(flag) return;
	if(now==n&&!is_ok()) return;
	if(now==n&&is_ok()) {
		flag=true;
		for(int i=0; i<n; i++){
			if(i!=0) cout<<' ';
			cout<<x[i];
		}
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
int main(){
	//freopen("alpha.in","r",stdin);
	//freopen("alpha.out","w",stdout);
	cin>>n;
	cin>>s1;
	cin>>s2;
	cin>>s3;
	dfs(0);
	return 0;
}
