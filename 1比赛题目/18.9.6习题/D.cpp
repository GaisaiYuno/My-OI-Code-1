#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 105 
using namespace std;
int n,t,m;
int a[maxn],b[maxn];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i],&b[i]);
        }
        sort(b+1,b+1+n);
        long long tmp=1;
        int ans=0;
        for(int i=1;i<=n;i++){
            tmp*=(long long)(b[i]+1);
            if(tmp<=m){
                ans=i;
            }else break;
        }
        printf("%d\n",ans);
    } 
} 
