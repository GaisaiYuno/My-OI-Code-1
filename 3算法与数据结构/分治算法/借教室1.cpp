//Âå¹È ½è½ÌÊÒ 
#include<iostream>
#define maxn 10000
using namespace std;
int n,m;
int r[maxn];
int d[maxn],s[maxn],t[maxn];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>r[i];
	for(int j=1;j<=m;j++) cin>>d[j]>>s[j]>>t[j];
	for(int k=1;k<=m;k++){
		for(int u=s[k];u<=t[k];u++){
				if(r[u]-d[k]>=0) r[u]-=d[k];
				else {
				cout<<-1<<endl<<k;
				return 0; 
				} 
			}
		}
	cout<<0; 
	return 0;
}
