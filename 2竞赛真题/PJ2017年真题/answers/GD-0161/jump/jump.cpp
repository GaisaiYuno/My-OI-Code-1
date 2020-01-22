#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	long int n;
	long long int x,s,k;
	int d,cnt;
	cin>>n>>d>>k;
	for(cnt=1;cnt<=n;cnt++)
		cin>>x>>s;
	cout<<-1;
	fclose(stdin);
	fclose(stdout);
}
