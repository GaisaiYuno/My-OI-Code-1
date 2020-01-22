#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int N,D,K,MAXN;
int ans=(1<<30)+1;
struct mem
{
    int x;
    int s;
}ns[500005];
int main()
{
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    scanf("%d%d%d",&N,&D,&K);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&ns[i].x,&ns[i].s);
        MAXN=max(ns[i].x,MAXN);
    }
    for(int i=0,aa=0;i<=MAXN;i++)
    {
        i+=D;
        aa+=ns[i].s;
        if(aa>=K)
        {printf("0\n");return 0;}
    }
    printf("-1\n");
    return 0;
}
