#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=810000;
int n,Q;pii a[N];
struct que{
    int a,b,id;
}b[N];
inline bool cmpque(const que &a,const que& b){return a.a<b.a;}
int tmp[N],m;
int cnttot[N];
int cntmat[N];
int cntval[N];
void add(int *A,int x,int v){
    for(;x<=m;x+=(x&(-x)))A[x]+=v;
}
int ask(int *A,int x){
    int ans=0;for(;x;x-=(x&(-x)))ans+=A[x];return ans;
}
multiset<int> gt;
int ans[N];
int main(){
    scanf("%d%d",&n,&Q);
    rep(i,1,n){
        scanf("%d%d",&a[i].fi,&a[i].se);
        tmp[++m]=a[i].fi;
        tmp[++m]=a[i].se;
    }
    rep(i,1,Q){
        scanf("%d%d",&b[i].a,&b[i].b);
        b[i].id=i;
        tmp[++m]=b[i].a;
        tmp[++m]=b[i].b;
    }
    sort(tmp+1,tmp+1+m);
    m=unique(tmp+1,tmp+1+m)-tmp-1;
    rep(i,1,n){
        a[i].fi=lower_bound(tmp+1,tmp+1+m,a[i].fi)-tmp;
        a[i].se=lower_bound(tmp+1,tmp+1+m,a[i].se)-tmp;
    }
    rep(i,1,Q){
        b[i].a=lower_bound(tmp+1,tmp+1+m,b[i].a)-tmp;
        b[i].b=lower_bound(tmp+1,tmp+1+m,b[i].b)-tmp;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+Q,cmpque);
    int db=1;

    reverse(a+1,a+1+n);
    reverse(b+1,b+1+Q);

    while(db<=Q&&b[db].a>a[1].fi)++db;

    for(int i=1;i<=n;i++){
        int j=i;
        while(j<n&&a[j+1].fi==a[i].fi)++j;
        rep(k,i,j){
            add(cnttot,a[k].se,1);
            multiset<int>::iterator it=gt.upper_bound(a[k].se);
            if(it==gt.end())continue;
            add(cntmat,*it,1);
            add(cntval,a[k].se,1);
            gt.erase(it);
        }
        rep(k,i,j)gt.insert(a[k].se);
        while(db<=Q&&((j==n)||(a[j+1].fi<b[db].a))){
            ans[b[db].id]=ask(cnttot,b[db].b);
            ans[b[db].id]-=ask(cntval,b[db].b)-(((ask(cntmat,m)-ask(cntmat,b[db].b))-(ask(cntval,m)-ask(cntval,b[db].b))));
            ++db;
        }
        i=j;
    }
    rep(i,1,Q)printf("%d\n",ans[i]);
    return 0;
}




