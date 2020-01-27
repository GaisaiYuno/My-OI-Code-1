#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,m;
int nex[maxn],extend[maxn];
char s[maxn],t[maxn];
inline void getnxt()
{
    nex[1]=m;nex[2]=0;
    while(t[1+nex[2]]==t[2+nex[2]])nex[2]++;
    for(int i=3,p0=2,r=p0+nex[p0]-1;i<=m;i++)
    {
        if(i+nex[i-p0+1]-1<r)nex[i]=nex[i-p0+1];
        else 
        {
            nex[i]=max(r-i+1,0);
            while(t[nex[i]+1]==t[i+nex[i]])nex[i]++;
            p0=i,r=i+nex[i]-1;
        }
    }
}
inline void getexnxt()
{
    extend[1]=0;
    while(s[1+extend[1]]==t[1+extend[1]])extend[1]++;
    for(int i=2,p0=1,r=p0+extend[p0]-1;i<=n;i++)
    {
        if(i+nex[i-p0+1]-1<r)extend[i]=nex[i-p0+1];
        else 
        {
            extend[i]=max(r-i+1,0);
            while(s[i+extend[i]]==t[extend[i]+1])extend[i]++;
            p0=i,r=i+extend[i]-1;
        }
    }
}
int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout); 
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1);m=strlen(t+1);
    getnxt();getexnxt();
    for(int i=1;i<=m;i++)printf("%d ",nex[i]);
    puts("");
    for(int i=1;i<=n;i++)printf("%d ",extend[i]);
    return 0;
}
