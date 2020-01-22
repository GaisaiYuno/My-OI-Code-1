#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a,v;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,ans=0;
	cin>>n>>d>>k;
	for(int i=0;i<n;++i){
		cin>>a>>v;
		if(v>0)ans+=v;
	}
	if(ans<k)cout<<-1;
	else cout<<2;
	return 0;
}
