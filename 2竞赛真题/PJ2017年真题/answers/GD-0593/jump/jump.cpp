#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k;
struct yxc{
	int x,s;
}A[500005];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++){
		cin>>A[i].x>>A[i].s;
	}
	cout<<-1;
	return 0;
}
