#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,d,k,a[500010],b[500010],ma=0;long long ans=0;
int main() {
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    int i,j;
    scanf("%d%d%d",&n,&d,&k);a[0]=0;bool f=false;
    for(i=1;i<=n;i++) {
        scanf("%d%d",&a[i],&b[i]);if(b[i]>0)ans+=b[i];ma=max(ma,a[i]-a[i-1]);
        if(!f&&b[i]>0)j=i,f=true;
    }
    if(ans<k) {
        printf("-1\n");return 0;
    }
    ans=abs(d-a[j]);
    printf("%d\n",ans);
}
