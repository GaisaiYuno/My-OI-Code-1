#include<iostream>
#include<cstdio>
#include<algorithm>
#define mid (l+r)/2
using namespace std;
int n,m,t;
const int N = 100010;
int q, cnt = 0;
int b[N], T[N];
int sum[N<<5], L[N<<5], R[N<<5];

int build(int l, int r)
{
    int rt = ++ cnt;
    sum[rt] = 0;
    if (l < r){
        L[rt] = build(l, mid);
        R[rt] = build(mid+1, r);
    }
    return rt;
}

int update(int pre, int l, int r, int x)
{
    int rt = ++ cnt;
    L[rt] = L[pre]; R[rt] = R[pre]; sum[rt] = sum[pre]+1;
    if (l < r){
        if (x <= mid) L[rt] = update(L[pre], l, mid, x);
        else R[rt] = update(R[pre], mid+1, r, x);
    }
    return rt;
}

int query(int u, int v, int l, int r, int k)
{
    if (l >= r) return l;
    int x = sum[L[v]] - sum[L[u]];
    if (x >= k) return query(L[u], L[v], l, mid, k);
    else return query(R[u], R[v], mid+1, r, k-x);
}

int read(){
   int s=0;
   char ch=getchar();
   while(ch<'0'||ch>'9'){ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s;
}

struct mx{
	int x;
	int y;
};

int fq(int x,int y,int z){
	int t = query(T[x-1], T[y], 1, m, z);
	return b[t];
}

bool cmp(mx a,mx b){
	return a.x<b.x;
}

mx aa[100001];
int a[100001];
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	t=read();
	for(int p=1;p<=t;p++){
		cnt=0;
		n=read();
		int mm=read();
		long long ans=0;
		for(register int i=1;i<=n;i++){
			aa[i].x=read();aa[i].y=read();
		}
		
		
		sort(aa+1,aa+n+1,cmp);
		for(int i=1;i<=n;i++)
			b[i]=aa[i].y,a[i]=aa[i].y;
		sort(b+1, b+1+n);
	    m = unique(b+1, b+1+n)-b-1;
	    T[0] = build(1, m);
	    for (int i = 1; i <= n; i ++){
	        int t = lower_bound(b+1, b+1+m, a[i])-b;
	        T[i] = update(T[i-1], 1, m, t);
	    }
	    
	    
		for(int i=1;i<=n;i++){
			if(i<=mm+1){
				int y=fq(i,n,mm-i+2);
				ans=max(ans,(long long )y*aa[i].x);
			}
			else
				break;
		}
		
		
		printf("%lld\n",ans);
	}
	return 0;
}

