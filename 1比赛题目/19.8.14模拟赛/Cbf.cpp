#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const double eps=1e-7;
const int maxn=100010;
int n,K,L,R,h,t;
int v[maxn],Log[maxn];
double f1[18][maxn],f2[18][maxn];
int f[18][maxn];
int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret*f;
}
double q1(int l,int r)
{
    int k=Log[r-l+1];
    return min(f1[k][l],f1[k][r-(1<<k)+1]);
}
double q2(int l,int r)
{
    int k=Log[r-l+1];
    return min(f2[k][l],f2[k][r-(1<<k)+1]);
}
int q(int l,int r)
{
    int k=Log[r-l+1];
    return min(f[k][l],f[k][r-(1<<k)+1]);
}
bool solve(double sta)
{
    int i,j;
    double ret=-99999999.9999;
    for(i=1;i<=n;i++)    f1[0][i]=v[i]-sta*i,f2[0][i]=v[i]+sta*i;
    for(j=1;(1<<j)<=n;j++) for(i=1;i+(1<<j)-1<=n;i++)
        f1[j][i]=min(f1[j-1][i],f1[j-1][i+(1<<j-1)]),f2[j][i]=min(f2[j-1][i],f2[j-1][i+(1<<j-1)]);
    for(i=1;i<=n;i++)
    {
        if(i>=L) ret=max(ret,f1[0][i]-q1(max(1,i-R+1),i-L+1));
        if(i<=n-L+1) ret=max(ret,f2[0][i]-q2(i+L-1,min(n,i+R-1)));
    }
    for(i=1;i<=n;i++)
    {
        ret=max(ret,v[i]-q(max(1,i-L+1),min(n,i+L-1))-sta*(L-1));
    }
    return ret>=K*sta;
}
void work()
{
    n=rd(),K=rd(),L=rd(),R=rd();
    int i,j;
    for(i=1;i<=n;i++)    f[0][i]=v[i]=rd();
    for(i=2;i<=n;i++)    Log[i]=Log[i>>1]+1;
    for(j=1;(1<<j)<=n;j++) for(i=1;i+(1<<j)-1<=n;i++) f[j][i]=min(f[j-1][i],f[j-1][i+(1<<j-1)]);
    double l=0,r=1000,mid;
//    printf("db %d\n",solve(0+eps)?1:0);
    while(r-l>eps)
    {
        mid=(l+r)/2;
        if(solve(mid))  l=mid;
        else    r=mid;
    }
    printf("%.4lf\n",l);
    return ;
}
int main()
{
		freopen("1.in","r",stdin);
    int T=rd();
    while(T--)  work();
    return 0;
}
/*
1
3 4 3 3
7 1 6 
*/ 
