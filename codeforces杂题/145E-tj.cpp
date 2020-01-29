#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
 
const int maxn = 1000000 + 10;
 
struct node{
    int l,r;
    int len4[2], len7[2], len47[2];
    int ans;
    int rev;
    int len;
}nod[maxn<<2];
 
char s[maxn];
char cmd[20];
 
void pushup(int o){
    int lson = o << 1;
    int rson = o << 1 | 1;
    nod[o].len4[0] = nod[lson].len4[0] + nod[rson].len4[0];
    nod[o].len7[0] = nod[lson].len7[0] + nod[rson].len7[0];
    nod[o].len47[0] = 0;
    nod[o].len47[0] = max(nod[lson].len4[0] + nod[rson].len7[0], nod[o].len47[0]);
    nod[o].len47[0] = max(nod[lson].len4[0] + nod[rson].len47[0], nod[o].len47[0]);
    nod[o].len47[0] = max(nod[lson].len47[0] + nod[rson].len7[0], nod[o].len47[0]);
    nod[o].ans = 0;
    nod[o].ans = max(nod[o].ans, nod[o].len4[0]);
    nod[o].ans = max(nod[o].ans, nod[o].len7[0]);
    nod[o].ans = max(nod[o].ans, nod[o].len47[0]);
 
 
    ///========================
 
 
    nod[o].len4[1] = nod[lson].len4[1] + nod[rson].len4[1];
    nod[o].len7[1] = nod[lson].len7[1] + nod[rson].len7[1];
    nod[o].len47[1] = 0;
    nod[o].len47[1] = max(nod[lson].len4[1] + nod[rson].len7[1], nod[o].len47[1]);
    nod[o].len47[1] = max(nod[lson].len4[1] + nod[rson].len47[1], nod[o].len47[1]);
    nod[o].len47[1] = max(nod[lson].len47[1] + nod[rson].len7[1], nod[o].len47[1]);
}
 
 
void deal(int o){
    nod[o].rev ^= 1;
    swap(nod[o].len4[0], nod[o].len4[1]);
    swap(nod[o].len7[0], nod[o].len7[1]);
    swap(nod[o].len47[0], nod[o].len47[1]);
    nod[o].ans = 0;
    nod[o].ans = max(nod[o].ans, nod[o].len4[0]);
    nod[o].ans = max(nod[o].ans, nod[o].len7[0]);
    nod[o].ans = max(nod[o].ans, nod[o].len47[0]);
}
void pushdown(int o){
 
    if (nod[o].rev){
        deal(o<<1);
        deal(o<<1|1);
        nod[o].rev = 0;
    }
}
 
void build(int l,int r,int o){
    nod[o].l = l;
    nod[o].r = r;
    nod[o].rev = 0;
    nod[o].len = r - l + 1;
    if (l == r){
        if (s[l] == '4'){
            nod[o].len4[0] = 1;
            nod[o].len7[0] = 0;
            nod[o].len47[0] = 0;
 
            nod[o].len4[1] = 0;
            nod[o].len7[1] = 1;
            nod[o].len47[1] = 0;
            nod[o].ans = 1;
            return;
        }
        else {
            nod[o].len4[0] = 0;
            nod[o].len7[0] = 1;
            nod[o].len47[0] = 0;
 
            nod[o].len4[1] = 1;
            nod[o].len7[1] = 0;
            nod[o].len47[1] = 0;
            nod[o].ans = 1;
            return;
        }
    }
 
 
    int m = l + r >> 1;
    build(l, m, o << 1);
    build(m+1, r, o<<1|1);
    pushup(o);
}
 
 
 
void update(int L,int R,int l,int r,int o){
    if (L <= l && r <= R){
        deal(o);
        return;
    }
    pushdown(o);
 
    int m = l + r >> 1;
    if (m >= L){
        update(L, R, l, m, o<<1);
    }
    if (m < R){
        update(L, R, m+1, r, o<<1|1);
    }
    pushup(o);
}
 
 
 
int main(){
 
    int n,q;
    scanf("%d %d", &n, &q);
 
    scanf("%s", s+1);
    build(1, n, 1);
 
    while(q--){
        scanf("%s", cmd);
        if (cmd[0] == 'c'){
            printf("%d\n", nod[1].ans);
        }
        else {
            int x,y;
            scanf("%d %d", &x, &y);
            update(x, y, 1, n, 1);
        }
    }
 
 
 
    return 0;
}

