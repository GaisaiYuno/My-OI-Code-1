#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
ll A,B,L,t,m;
int n;
ll cal(ll pos)
{
    return 1LL*(pos-1)*B+A;
}
bool check(ll pos)
{
    ll fin=cal(pos);
    if(fin>t) return false;
    ll st=cal(L);
    ll sum=((st+fin)*(pos-L+1))/2;
    if(sum<=m*t) return true;
    else return false;
}
int main()
{
//	freopen("stairs10.in", "r", stdin);
//	freopen("stairs10.out", "w", stdout);
    scanf("%lld%lld%d",&A,&B,&n);
    while(n--)
    {
        scanf("%lld%lld%lld",&L,&t,&m);
        ll l=L,r=L+1+(t*m)/cal(L);
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(check(mid)) l=mid+1;
            else r=mid-1;
        }
        if(r<=L-1) printf("-1\n");
        else printf("%lld\n",r);
    }
    return 0;
}
