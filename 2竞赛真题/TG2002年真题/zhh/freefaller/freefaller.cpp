#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define fu(a,b,c) for(int a=b;a<c;a++)
using namespace std;
int n,ans;
double h,s,v,l,k;
int main(){
	freopen("freefaller.in","r",stdin);
	freopen("freefaller.out","w",stdout);
	cin>>h>>s>>v>>l>>k>>n;
	fu(i,0,n){
		if(i>s-sqrt(h/5)*v-0.0001&&i<s-sqrt((h-k)/5)*v+l+0.0001){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
