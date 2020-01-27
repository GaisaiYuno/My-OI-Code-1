#include<cstdio>
#include<algorithm>
using namespace std;
struct ele{
    long long k,x;
}e[500005];
long long tree[500005],a[500005];
long long sum[500005];
long long n,m,last;
inline long long read(){
    long long ret=0;char c=getchar();
    while((c<'0')||(c>'9'))c=getchar();
    while((c>='0')&&(c<='9'))ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
    return ret;
}
inline bool cmp(ele k1,ele k2){
    if(k1.x!=k2.x)return k1.x<k2.x;
    else return k1.k<k2.k;
}
inline long long lowbit(long long k){return k&-k;}
inline long long query(long long k){long long ans=0;for(;k;k-=lowbit(k))ans+=tree[k];return ans;}
void add(long long k){for(;k<=n;k+=lowbit(k))tree[k]++;}
int main(){
	freopen("sort7.in","r",stdin);
	freopen("sort7.out","w",stdout);
    n=read();m=read();
    for(long long i=1;i<=n;i++)e[i].x=read(),e[i].k=i;
    sort(e+1,e+1+n,cmp);
    for(long long i=n;i;i--)if(e[i].x!=e[i+1].x)a[e[i].k]=i;
    else a[e[i].k]=a[e[i+1].k];
    for(long long i=1;i<=n;i++){
        sum[i]=sum[i-1]+query(n)-query(e[i].k);
        add(e[i].k);
    }
    printf("%I64d\n",sum[n]);
    last=0;
    for(long long i=1;i<=m;i++){
        long long p=read();
        if(a[p]>last)last=a[p];
        printf("%I64d\n",sum[n]-sum[last]);
    }
}
