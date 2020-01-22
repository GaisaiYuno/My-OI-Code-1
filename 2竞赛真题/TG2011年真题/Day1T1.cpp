#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10005
using namespace std;
int n;
struct carpet{
    int a;
    int b;
    int g;
    int k;
}c[maxn];
int main(){
//	freopen("carpet.in","r",stdin);
//	freopen("carpet.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d",&c[i].a,&c[i].b,&c[i].g,&c[i].k);
    }
    long long x,y;
    cin>>x>>y;
    int color=-1;
    for(int i=1;i<=n;i++){
        if(x>=c[i].a&&x<=(long long)c[i].a+c[i].g&&y>=c[i].b&&y<=(long long)c[i].b+c[i].k){
            color=i;
        }
    }
    printf("%d\n",color);
}
