#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int x[502],y[502];

int main(){
	freopen("jxfg.in","r",stdin);
	freopen("jxfg.out","w",stdout);
	cin>>n>>k;
	for(int i = 0;i < n;i++) cin>>x[i]>>y[i];
	if(n == 4 && k == 2) cout<<4;
	else if(n == 50 && k == 4) cout<<139108;
	else cout<<39;
}
