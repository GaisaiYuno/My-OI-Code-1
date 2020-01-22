#include<bits/stdc++.h>
#define ll long long
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
#define zhh 1000005
#define inf 0x7fffffff
#define eps 1e-8
#define mod 1000000007
using namespace std;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
inline void fp(ll x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>=10) fp(x/10);
    putchar(x%10+'0');
}
int n,m;
ll ans;
ll tg[zhh];
list<ll>mq[zhh];
int main(){
    freopen("problem2.in","r",stdin);
    freopen("problem2.out","w",stdout);
    n=read(),m=read();
    fu(i,1,n){
        mq[i].push_back(0);
    }
    while(m--){
        int op=read();
        if(op==1){
            int i=read();
            ll x=read();
            ll y=mq[i].front();
            mq[i].pop_front();
            mq[i].push_front((y-x+mod)%mod);
            mq[i].push_front(x);
        }
        else if(op==2){
            int i=read();
            ll x=mq[i].front();
            mq[i].pop_front();
            ll y=mq[i].front();
            mq[i].pop_front();
            mq[i].push_front((x+y)%mod);
            fp(x);puts("");
        }
        else if(op==3){
            int i=read();
            ll x=read();
            ll y=(mod-mq[i].back())%mod;
            mq[i].pop_back();
            mq[i].push_back((x-y+mod)%mod);
            mq[i].push_back((mod-x)%mod);
        }
        else if(op==4){
            int i=read();
            ll x=mq[i].back();
            mq[i].pop_back();
            ll y=mq[i].back();
            mq[i].pop_back();
            mq[i].push_back((x+y)%mod);
            fp((mod-x)%mod);puts("");
        }
        else if(op==5){
            int i=read();
            ll d=read();
            ll l1=mq[i].front();
            mq[i].pop_front();
            mq[i].push_front((d+l1)%mod);
            ll l2=mq[i].back();
            mq[i].pop_back();
            mq[i].push_back((l2-d+mod)%mod);
        }
        else{
            int i=read(),j=read();
            ll x=mq[i].back();
            mq[i].pop_back();
            ll y=mq[j].front();
            mq[j].pop_front();
            mq[j].push_front((x+y)%mod);
            mq[i].splice(mq[i].end(),mq[j]);
            mq[j].push_back(0);
        }
    }
    return 0;
}
