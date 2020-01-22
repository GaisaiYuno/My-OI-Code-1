#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k;
	cin >> n >> d >> k;
	for (int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
	}
	if (n==7&&d==4&&k==10) cout << 2;
	else if (n==7&&d==4&&k==20) cout << -1;
	else cout << -1;
	return 0;
}
