#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int L[N],R[N],ok[N];
vector<int> a[N];
ll dis(int x1,int y1,int x2,int y2){
    ll res = x2 - x1;
    if(L[y1]==L[y2]&&R[y1]==R[y2]){
        ll a = y2 - L[y2], b = R[y2] - y2;
        ll c = y1 - L[y2], d = R[y2] - y1;
    //    cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
        return res + min(a+c,b+d);
    }
    return res + abs(y1-y2);
}
ll f[N][2];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,k,q; cin>>n>>m>>k>>q;
    for(int i=1;i<=k;i++){
        int x,y; cin>>x>>y;
        a[x].push_back(y);
    }
    for(int i=1;i<=q;i++){
        int x; cin>>x;
        ok[x] = 1;
    }
    L[0] = -inf;
    for(int i=1;i<=m;i++){
        L[i] = L[i-1];
        if(ok[i]) L[i] = i;
    }
    R[m+1] = inf;
    for(int i=m;i>=1;i--){
        R[i] = R[i+1];
        if(ok[i]) R[i] = i;
    }
    int pre = 1;
    sort(a[1].begin(),a[1].end());
    if(a[1].size()){
        f[1][0] = f[1][1] = a[1].back()-1;
        a[1][0] = a[1].back();
    }
    else{
        a[1].push_back(1);
        f[1][0] = f[1][1] = 0;
    }
    for(int i=2;i<=n;i++){
        //f[i][0], f[i][1];
        if(a[i].size()==0) continue;
        sort(a[i].begin(),a[i].end());
//        int l = a[i][0], r = a[i].back();
        f[i][0] = min(f[pre][0]+dis(pre,a[pre][0],i,a[i].back()),f[pre][1]+dis(pre,a[pre].back(),i,a[i].back()));
        f[i][1] = min(f[pre][0]+dis(pre,a[pre][0],i,a[i][0]),f[pre][1]+dis(pre,a[pre].back(),i,a[i][0]));
        f[i][0] += a[i].back()-a[i][0];
        f[i][1] += a[i].back()-a[i][0];
        pre = i;
    }
//    for(int i=1;i<=n;i++) cout<<f[i][0]<<' '<<f[i][1]<<endl;
    ll ans = min(f[pre][0],f[pre][1]);
    cout<<ans<<endl;
}
