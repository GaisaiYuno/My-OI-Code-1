#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME "trains"

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int MAXN = 2e5 + 5;
int bd = 30;

int n, m, k;
vector <pii> poss[MAXN];
vector <pii> free_pos;
vector <int> next_pos;

vector <bool> used;
vector <vector <int> > binup;

int topsort(int v) {
    used[v] = true;
    if (!used[next_pos[v]]) {
        topsort(next_pos[v]);
    }

    binup[0][v] = next_pos[v];
    for (int i = 1; i < szof(binup); ++i) {
        binup[i][v] = binup[i - 1][binup[i - 1][v]];
    }
    return 0;
}



int main() {        
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a;--b;--c;
        poss[c].puba(mapa(a, b));
    }

    for (int i = 0; i < k; ++i) {
        sort(bend(poss[i]));
        int prev = 0;
        for (auto p: poss[i]) {
            if (prev < p.ff) {
                free_pos.puba(mapa(prev, p.ff));
            }
            prev = p.ss;
        }
        if (prev < n - 1) {
            free_pos.puba(mapa(prev, n - 1));
        }
    }

    vector <tuple<int, int, int>> scanline;

    for (int i = 0; i < szof(free_pos); ++i) {
        //cerr << free_pos[i].ff << " " << free_pos[i].ss << endl;
        scanline.puba(make_tuple(free_pos[i].ff, 0, i));
        scanline.puba(make_tuple(free_pos[i].ss, 1, i));
    }

    sort(bend(scanline));

    set <pii> now;
    
    next_pos.resize(szof(free_pos));

    vector <int> to(n);

    int c = 0;

    for (int i = 0; i < szof(scanline); ++i) {
        int x, type, id;
        tie(x, type, id) = scanline[i];
        while (c < x) {
            if (szof(now)) {
                to[c] = now.rbegin() -> ss;
                //cerr << c << " " << to[c] << endl;
            } else {
                to[c] = -1;
            }
            ++c;
        }
        if (type == 0) {
            now.insert(mapa(free_pos[id].ss, id));                        
        } else {
            now.erase(mapa(free_pos[id].ss, id));
            if (szof(now)) {
                next_pos[id] = now.rbegin() -> ss;
            } else {
                next_pos[id] = id;
            }
            //cerr << "id: " << id << " " << next_pos[id] << endl;
        }
    }

    while (c < n) {
        if (szof(now)) {
            to[c] = now.rbegin() -> ss;
            //cerr << c << " " << to[c] << endl;
        } else {
            to[c] = -1;
        }
        ++c;
    }

    bd = 0;
    for (int j = 1; j <= szof(free_pos); j *= 2, ++bd);

    binup.resize(bd);

    for (auto& v: binup) {
        v.resize(szof(free_pos));
    }

    used.resize(szof(free_pos));

    for (int i = 0; i < szof(free_pos); ++i) {
        if (!used[i]) {
            topsort(i);
        }
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;--r;
        int ans = 0;
        int pos = to[l];
        if (pos == -1) {
            cout << "-1\n";
            continue;
        }
        for (int j = bd - 1; j >= 0; --j) {
            int tmp = binup[j][pos];
            if (free_pos[tmp].ss < r) {
                ans += 1 << j;
                pos = tmp;
            }
        }
        if (free_pos[pos].ss < r) {
            pos = binup[0][pos];
            ++ans;
        }
        if (free_pos[pos].ss < r) {
            cout << "-1\n";
        } else {
            cout << ans + 1 << "\n";
        }
    }

    return 0;
}
