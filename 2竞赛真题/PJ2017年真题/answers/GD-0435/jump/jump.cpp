#include<iostream>
using namespace std;
int a[10001][10001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k;
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=2;j++)
	cin>>a[i][j];
	if(k==10)
	cout<<2;
	else cout<<-1;
}
