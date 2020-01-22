#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,q,a[1111],b[1111],c[1111],d[11];
int main() {
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
    int i,j;
    d[1]=10;d[2]=100;d[3]=1000;d[4]=10000;d[5]=100000;d[6]=1000000;d[7]=10000000;d[8]=100000000;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=q;i++){
        scanf("%d%d",&b[i],&c[i]);
    }
    for(i=1;i<=q;i++) {
        bool f=false;
        for(j=1;j<=n;j++) {
            if(a[j]%d[b[i]]==c[i]&&!f)printf("%d\n",a[j]),f=true;
        }
        if(!f)printf("-1\n");
    }
}
