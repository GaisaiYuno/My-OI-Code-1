//O(n^2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 200005
#define INF 0x7ffffffffffff
using namespace std;
inline int qread() {
    int x=0,sign=1;
    char c=getchar();
    while(c<'0'||c>'9') {
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*sign;
}
int n,m;
long long s;
struct section {
    int l;
    int r;
} q[maxn];
int v[maxn],w[maxn];
long long sum[maxn];
long long cnt[maxn];
long long maxw,minw;
long long cha;
long long get_y(int w0) {
    long long tmp=0;
    memset(sum,0,sizeof(sum));
    memset(cnt,0,sizeof(cnt));
    for(int j=1; j<=n; j++) {
        if(w[j]<w0) {
            sum[j]=sum[j-1];
            cnt[j]=cnt[j-1];
        } else {
            sum[j]=sum[j-1]+v[j];
            cnt[j]=cnt[j-1]+1;
        }
    }
    for(int j=1; j<=m; j++) {
        tmp=tmp+(sum[q[j].r]-sum[q[j].l-1])*(cnt[q[j].r]-cnt[q[j].l-1]);
    }
    cha=abs(tmp-s);
    return tmp;
}
int main() {
    n=qread();
    m=qread();
    cin>>s;
    maxw=0;
    minw=INF;
    for(int i=1; i<=n; i++) {
        w[i]=qread();
        v[i]=qread();
        maxw=max(maxw,(long long)w[i]);
        minw=min(minw,(long long)w[i]);
    }
    for(int i=1; i<=m; i++) {
        q[i].l=qread();
        q[i].r=qread();
    }
    long long ans=INF;
    long long l=minw-1,r=maxw+1;
    long long mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(get_y(mid)>s)  l=mid+1;
        else r=mid-1;
        if(cha<ans) ans=cha;
    }
    printf("%lld",ans);
}

