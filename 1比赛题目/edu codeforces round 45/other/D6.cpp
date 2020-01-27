#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <array>
#include <bitset>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    if (a != 1 && b != 1){
        cout << "NO" << endl;
        return 0;
    }

    vector<string> ans(n, string(n, '0'));
    if (a == 1 && b == 1){
        if (n == 2 || n == 3){
            cout << "NO" << endl;
            return 0;
        }
        REP(i,n-1){
            ans[i][i+1] = ans[i+1][i] = '1';
        }
    }else{
        int x = max(a, b);
        REP(i,n-x){
            ans[i][i+1] = ans[i+1][i] = '1';
        }
        if (b == x){
            REP(i,n) REP(j,n){
                if (i == j) continue;
                if (ans[i][j] == '1') ans[i][j] = '0';
                else ans[i][j] = '1';
            }
        }
    }
    cout << "YES" << endl;
    REP(i,n) cout << ans[i] << endl;

    return 0;
}

