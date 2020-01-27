#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<sstream>
#include<cctype>
#include<map>
#include<stack>
#include<queue>
#include<list>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
const double PI = atan(1.0)*4;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int maxn = 100010;

int a[maxn];
int b[maxn];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n;
    ll sa = 0, sb = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    a[0] = b[0] = 0;
    int an = n, bn = n;
    int turn = 1;
    while(an || bn)
    {
        if(turn)
        {
            turn = 0;
            if(b[bn] < a[an])
            {
                sa += a[an];
                --an;
            }
            else
                --bn;
        }
        else
        {
            turn = 1;
            if(a[an] < b[bn])
            {
                sb += b[bn];
                --bn;
            }
            else
                --an;
        }
    }
    printf("%I64d\n", sa - sb);
    return 0;
}
