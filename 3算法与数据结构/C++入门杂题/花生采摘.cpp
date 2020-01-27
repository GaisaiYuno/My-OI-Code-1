//Âå¹È »¨Éú²ÉÕª
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define maxn 5000
using namespace std;
int m,n,k,ans;
struct peanut{
    int x;
    int y;
    int value;
    int time;
}a[maxn];
int comp(peanut p,peanut q){
    return p.value>q.value;
}
int dist(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
int main(){
    int temp,u;
    int cnt=0;
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) {
            cin>>temp;
            if(temp!=0){
                cnt++; 
                a[cnt].x=i;
                a[cnt].y=j;
                a[cnt].value=temp;
            }
        }
    }
    sort(a+1,a+1+cnt,comp);
    for(int i=1;i<=cnt;i++){
        u=a[i].x;
        if(i==1) a[i].time=a[i].x+1;
        else a[i].time=a[i-1].time+dist(a[i].x,a[i].y,a[i-1].x,a[i-1].y);
        if(a[i].time+u<=k) ans+=a[i].value;
    }
    cout<<ans;
    return 0;
} 
