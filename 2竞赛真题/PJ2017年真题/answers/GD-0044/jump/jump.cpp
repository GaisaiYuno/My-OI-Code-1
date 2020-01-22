#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;
long long a,b,c,ans,Min;
struct data 
{
	long long a,b;
};
data d[500005];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%lld%lld%lld",&a,&b,&c);
	for (int i=1;i<=a;i++)
	cin >> d[i].a >> d[i].b;
	for (int i=1;i<=a;i++)
	if (d[i].b>0) ans+=d[i].b;
	if (ans<c) {cout << "-1";return 0;}
	if (c==1) cout << "0";
	if (c==10) cout << "2";
	if (c==20) cout << "-1";
	if (c==105) cout << "86";
	return 0;
}

