#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k;
	int x[100000],s[100000];
	int o=0;
	cin>>n>>d>>k;
	for(int i=0;i<n;++i){
		cin>>x[i]>>s[i];
		if(s[i]>=0)
		o+=s[i];
	}
	if(o<k){
		cout<<"-1";
	}
	else{
		cout<<d/2;
	}
	return 0;
}
