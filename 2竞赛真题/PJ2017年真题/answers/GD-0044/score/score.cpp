#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
int a,b,c,ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin >> a >> b >> c;
	cout << a/10*2+b/10*3+c/10*5;
	return 0;
}
