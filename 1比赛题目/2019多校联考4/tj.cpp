#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#define space putchar(' ')
#define enter putchar('\n')
using namespace std;
typedef unsigned long long ll;

template <class T>
void read(T &x){
    char c;
    bool op = 0;
    while(c = getchar(), c < '0' || c > '9')
        if(c == '-') op = 1;
    x = c - '0';
    while(c = getchar(), c >= '0' && c <= '9')
        x = x * 10 + c - '0';
    if(op) x = -x;
}
template <class T>
void write(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 50005, M = 3000000;
int n, Q, idx = 1, a[N], root[N] = {1}, son[M][2], sze[M];

void insert(int i, int x){
    int now = root[i] = ++idx;
    int old = root[i - 1];
    for(int i = 31; i >= 0; i--){
        sze[now] = sze[old] + 1;
        if((x >> i) & 1) son[now][0] = son[old][0], son[now][1] = ++idx;
        else son[now][1] = son[old][1], son[now][0] = ++idx;
        now = son[now][(x >> i) & 1];
        old = son[old][(x >> i) & 1];
    }
    sze[now] = sze[old] + 1;
}
int query(int l, int r, int x){
    int old = root[l], now = root[r], ans = 0;
    for(int i = 31; i >= 0; i--){
        bool dir = (x >> i) & 1;
        int delta_sze = sze[son[now][!dir]] - sze[son[old][!dir]];
        if(delta_sze) now = son[now][!dir], old = son[old][!dir], ans = ans << 1 | 1;
        else now = son[now][dir], old = son[old][dir], ans = ans << 1;
    }
    return ans;
}

int main(){
    read(n), read(Q);
    for(int i = 1; i <= n; i++)
        read(a[i]);
    for(int i = 1; i <= n; i++)
        insert(i, a[i]);
    int l, r, x;
    while(Q--){
        read(x), read(l), read(r);
        write(query(l, r + 1, x)), enter;
    }
    return 0;
}
