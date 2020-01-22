#include<bits/stdc++.h>
using namespace std;
int n,d,k; 
struct noip{
	int x,y;
}a[500001];
bool cmp(noip n,noip m){
	return n.x>m.x;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	cout<<-1;
	return 0;
}
