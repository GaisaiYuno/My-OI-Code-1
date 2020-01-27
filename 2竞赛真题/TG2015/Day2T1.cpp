#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50005
using namespace std;
int ml;
int n,m;
int a[maxn];
int check(int dis){
    int cnt=0;
    int last=0;
    for(int i=1;i<=n;i++){
        if(a[i]-a[last]<dis){
            cnt++;
        }else last=i; 
    }
    if(a[n+1]-a[last]<dis) cnt++;
    if(cnt<=m) return 1;
    else return 0;
}
int main(){
//	freopen("stone.in","r",stdin);
//	freopen("stone.out","w",stdout);
    scanf("%d %d %d",&ml,&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int l=0,r=ml,ans=0;
    int mid;
    a[0]=0;
    a[n+1]=ml;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ans=max(ans,mid);
            l=mid+1;
        }else r=mid-1;
    }
    printf("%d\n",ans);
}
