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
    int n;
    cin >> n;
    map<int, ll> cnt;
    ll ans = 0;
    REP(i,n){
        string s;
        cin >> s;
        int mi = 0, x = 0;
        for (char c : s){
            if (c == '(') x++;
            else x--;
            mi = min(mi, x);
        }

        if (mi == 0 && x == 0){
            ans++;
        }
        if (mi == 0 && x >= 0){
            ans += cnt[-x];
        }
        if (mi == x && x <= 0){
            ans += cnt[-x];
        }

        if ((mi == 0 && x >= 0) || (mi == x)){
            cnt[x]++;
        }
    }
    cout << ans << endl;

    return 0;
}
