#include<bits/stdc++.h>
using namespace std;
int x[1000],s[1000];
int main(){
	int n,d,k,ans=0;
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++) cin>>x[i]>>s[i];
	for(int i=1;i<=n;i++) if(s[i]>0)ans+=s[i];
	if(ans<k) cout<<"-1";
}

/*
7 4 20
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2
*/
