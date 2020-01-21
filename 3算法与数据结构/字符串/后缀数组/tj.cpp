#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

#define maxn 140080
#define inf 0x3f3f3f3f

int key[maxn],belong[maxn],str[maxn];
bool vis[120];
int sa[maxn],t[maxn],t2[maxn],c[maxn];
int height[maxn],Rank[maxn];  //注意尽量不要用rank，我一开始就是这样CE的

void build(int * s,int n,int m) //倍增法构建后缀数组
{
    int i,*x = t,*y = t2;
    for(i = 0;i < m;i++) c[i] = 0;
    for(i = 0;i < n;i++) c[x[i]=s[i]]++;
    for(i = 1;i < m;i++) c[i] += c[i-1];
    for(i = n-1;i >= 0;i--) sa[--c[x[i]]] = i;
    for(int k = 1;k <= n;k <<= 1)
    {
        int p = 0;
        for(i = n-k;i < n;i++) y[p++] = i;
        for(i = 0;i < n;i++) if(sa[i] >= k)y[p++] = sa[i] - k;
        for(i = 0;i < m;i++) c[i] = 0;
        for(i = 0;i < n;i++) c[x[y[i]]]++;
        for(i = 0;i < m;i++) c[i] += c[i-1];
        for(i = n-1;i >= 0;i--) sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1;
        x[sa[0]] = 0;
        for(i = 1;i < n;i++)
            x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1] + k] == y[sa[i]+k] ? p-1:p++;
        if(p >= n) break;
        m = p;
    }
}

void getHeight(int *s,int n) //求出height
{
    int i,j,k = 0;
    for(i = 0;i < n;i++) Rank[sa[i]] = i;
    for(i = 0;i < n;i++)
    {
        if(k) k--;
        int j = sa[Rank[i]-1];
        while(s[i+k] == s[j+k]) k++;
        height[Rank[i]] = k;
    }
}

bool judge(int n,int len,int num)
{
    int cnt = 0;
    memset(vis,0,sizeof(vis));
    vis[0] = 1;
    if(!vis[belong[sa[0]]])
    {
        cnt++;
        vis[belong[sa[0]]] = 1;
    }
    for(int i = 1;i < n;i++)
    {
        if(height[i] < len)
        {
            cnt = 0;
            memset(vis,0,sizeof(vis));
            vis[0] = 1;
            if(!vis[belong[sa[i]]])
            {
                vis[belong[sa[i]]] = 1;
                cnt++;
            }
        }
        else
            if(!vis[belong[sa[i]]])
            {
                cnt++;
                vis[belong[sa[i]]] = 1;
            }
        if(cnt >= num) return 1;
    }
    return 0;
}

void print(int n,int len,int num)
{
    int cnt = 0;
    memset(vis,0,sizeof(vis));
    vis[0] = 1;
    if(!vis[belong[sa[0]]]) cnt ++;
    vis[belong[sa[0]]] = 1;

    for(int i = 1;i < n;i++)
    {
        if(height[i] < len)
        {
            if(cnt >= num)
            {
                for(int j = sa[i-1];j < sa[i-1]+len;j++)
                    printf("%c",str[j] - 18);
                printf("\n");
            }
            cnt = 0;
            memset(vis,0,sizeof(vis));
            vis[0] = 1;
            if(!vis[belong[sa[i]]])
            {
                cnt ++;
                vis[belong[sa[i]]] = 1;
            }
        }
        if(!vis[belong[sa[i]]])
        {
            cnt++;
            vis[belong[sa[i]]] = 1;
        }
    }
    if(cnt >= num)
    {
        for(int i = sa[n-1];i < sa[n-1]+len;i++)
            printf("%c",str[i]-18);
        printf("\n");
    }
}

inline int max(int a,int b){return a > b ? a : b;}

char s[1008];
int main()
{
    int n;
    bool flag = true;
    while(scanf("%d",&n) != EOF && n)
    {
        if(!flag) printf("\n");
        else flag = false;
        memset(belong,0,sizeof(belong));
        int pos = 0,cat = 1;
        int l = 0,r = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%s",s);
            int len = strlen(s);
            r = max(r,len);
            for(int j = 0;j < len;j++)
            {
                str[pos+j] = (int)(s[j]) + 18;
                belong[pos+j] = i;
            }
            str[pos+len] = cat++;
            pos = pos + len + 1;
        }
        str[pos] = 0;
        build(str,pos+1,150);
        getHeight(str,pos+1);
        int maxlen = 0;
        judge(pos+1,6,n/2+1); 
        while(l <= r)
        {
            int mid = (l+r) >> 1;
            if(judge(pos+1,mid,n/2+1))
            {
                maxlen = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if(maxlen == 0) printf("?\n");
        else print(pos+1,maxlen,n/2+1);
    }
    return 0;
}
