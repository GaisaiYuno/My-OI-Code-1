#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef long long ll;
const int M=(int)150005,N=(int)550;
void rd(int &x) {
    static char c;x=0;
    while(c=getchar(),c<48);
    do x=(x<<3)+(x<<1)+(c^48);
    while(c=getchar(),c>47);
}
void pt(int x) {
    if(!x) putchar('0');
    static int Stk[30],tp=0;
    for(; x; x/=10) Stk[tp++]=x%10;
    while(tp) putchar(Stk[--tp]^48);
}
void ptk(const int &x) {pt(x);putchar(' ');}
void ptn(const int &x) {pt(x);putchar('\n');}
int Num[M<<1],cst[M<<1];
int hp[M];
int H;
struct block{
    int l,r;
    int sum[M];
    void Init() {
        FOR(i,l,r) {
            sum[Num[i]]+=cst[i];
            if(sum[Num[i]]>1e9) sum[Num[i]]=1e9;
        }
        FOR(i,0,16) {
            FOR(j,0,H) {
                if((1<<i)&j) {
                    sum[j^(1<<i)]+=sum[j];
                    if(sum[j^(1<<i)]>1e9) sum[j^(1<<i)]=1e9;
                }
            }
        }
    }
}blk[N];
int Ans[M<<1];
int main() {
    freopen("monster.in","r",stdin);
    freopen("monster.out","w",stdout);
    int n,m;
    rd(n);
    FOR(i,0,n-1) rd(hp[i]);
    FOR(i,0,20) {
        if((1<<i)>=n) {
            H=(1<<i)-1;
            break;
        }
    }
    rd(m);
    FOR(i,1,m) {
        rd(Num[i]);
        rd(cst[i]);
        Num[i]&=H;
    }
    int S=(m==1)?1:sqrt(m*log2(n));
    FOR(i,1,m/S) {
        blk[i].l=(i-1)*S+1;
        blk[i].r=i*S;
    }
    int top=m/S;
    if(m%S) {
        blk[top+1].l=top*S+1;
        blk[top+1].r=m;
        top++;
    }
    FOR(i,1,top) blk[i].Init();
    FOR(i,0,n-1) {
        int tmp=hp[i];int pos=-1;
        FOR(j,1,top) {
            if(tmp<=blk[j].sum[i]) {pos=j;break;}
            else tmp-=blk[j].sum[i];
        }
        if(!~pos) continue;
        FOR(j,blk[pos].l,blk[pos].r) {
            if((i&Num[j])==i) {
                if(tmp<=cst[j]) {Ans[j]++;break;}
                else tmp-=cst[j];
            }
        }
    }
    int res=n;
    FOR(i,1,m) ptn(res-=Ans[i]);
    return 0;
}
