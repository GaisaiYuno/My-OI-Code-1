#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(register int i=(a),____u=(b);i<=____u;++i)
#define DEP(i,a,b) for(register int i=(a),____u=(b);i>=____u;--i)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define gc getchar
#define pc putchar
#define in read()
#define fin read()
#define mp make_pair
#define fi first
#define se second
#define for_edge(u,i) for(int i=first[u];i;i=bian[i].next)
#define ms(a,b) memset((a),(b),sizeof((a)))
typedef long long LL;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef complex<double> cp;
typedef pair<int,int> pii;
const db Pi=acos(-1.0);
const db eps = 1e-9;
const db dinf = 1e17;
const int inf = 1e9;
const LL linf = 1e17;
const int N=1e6+5;
const int mod=1e9+7;
int read(){
	int res=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) res=(res<<1)+(res<<3)+(c^'0');
	return res*f;
}

int ksm(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)if(res&1)res=1ll*res*a%mod;return res;
}
int A[N],h[N],H[N];
/*int main()
{
//	freopen("in.in","r",stdin);
    int n,K;
    n=read();K=read();
    FOR(i,1,n) A[i]=read(),H[A[i]]++;
    sort(A+1,A+n+1);int p=1;
    FOR(i,1,n){
        while(A[p]<A[i]-K)p++;
        h[A[p]]++;h[A[i]]--;
    }
    int Ans=0;
    for(int i=1;i<N;i++)h[i]+=h[i-1],Ans+=(!h[i])*H[i];
    cout<<Ans<<'\n';
    return 0;
}*/
char str[N],sta[N];
int tp,f[N],g[N],n;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		tp=0;
		for(int j=0;str[j];j++){
			if(str[j]==')'){if(sta[tp]=='(')tp--;else sta[++tp]=')';}
			if(str[j]=='(')sta[++tp]='(';
		}
		int s[2]={0};
		for(int i=1;i<=tp;i++)s[sta[i]=='(']++;
		if(s[0]==0)f[s[1]]++;
		if(s[1]==0)g[s[0]]++;
	}
	LL ans=0;
	for(int i=0;i<=(int)4e5;i++)ans+=1ll*f[i]*g[i];
	cout<<ans<<'\n';
	return 0;
}
