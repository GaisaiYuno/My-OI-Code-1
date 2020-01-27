#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
#define maxn 120000  
struct node  
{  
    int lenl,lenr,len,col;  
} sum[maxn];  
int x[12000];//ÀëÉ¢»¯  
void setting(int rt,int num)  
{  
    sum[rt].len=sum[rt].lenl=sum[rt].lenr=num;  
}  
void pushup(int rt,int l,int r)  
{  
    sum[rt].lenl=sum[rt<<1].lenl;  
    sum[rt].lenr=sum[rt<<1|1].lenr;  
    sum[rt].len=max(max(sum[rt<<1].len,sum[rt<<1|1].len),sum[rt<<1].lenr+sum[rt<<1|1].lenl);  
    int m=(l+r)>>1;  
    int temlenl=x[m]-x[l-1];  
    int temlenr=x[r]-x[m];  
    if(sum[rt<<1].lenl==temlenl)sum[rt].lenl+=sum[rt<<1|1].lenl;  
    if(sum[rt<<1|1].lenr==temlenr)sum[rt].lenr+=sum[rt<<1].lenr;  
  //  printf("[%d,%d]  [%d,%d]\n",l,m,x[l-1],x[m]); 
  //  printf("%d %d\n",temlenl,temlenr); 
}  
void pushdown(int rt,int l,int r)  
{  
    if(sum[rt].col!=-1)  
    {  
        sum[rt<<1].col=sum[rt<<1|1].col=sum[rt].col;  
        int m=(l+r)>>1;  
        int temlenl=x[m]-x[l-1];  
        int temlenr=x[r]-x[m];  
        setting(rt<<1,temlenl*sum[rt].col);  
        setting(rt<<1|1,temlenr*sum[rt].col);  
        sum[rt].col=-1;  
    }  
}  
void build(int l,int r,int rt)  
{  
    setting(rt,0);  
    sum[rt].col=-1;  
    if(l==r)return ;  
    int m=(l+r)>>1;  
    build(lson);  
    build(rson);  
}  
void update(int l,int r,int rt,int L,int R,int c)  
{  
    if(l>=L&&r<=R)  
    {  
        sum[rt].col=c;  
        setting(rt,(x[r]-x[l-1])*c);  
        return ;  
    }  
    pushdown(rt,l,r);  
    int m=(l+r)>>1;  
    if(m>=L)update(lson,L,R,c);  
    if(m<R) update(rson,L,R,c);  
    pushup(rt,l,r);  
}  
int query(int l,int r,int rt)  
{  
    if(l==r)return x[l];  
    int m=(l+r)>>1;  
    pushdown(rt,l,r);  
    if(sum[rt<<1].len==sum[1].len)return query(lson);  
    else if(sum[rt<<1].lenr+sum[rt<<1|1].lenl==sum[1].len)return x[m]-sum[rt<<1].lenr+1;  
    else return query(rson);  
}  
int sea(int num,int l,int r)  
{  
    int mid=(l+r)>>1;  
    while(l<=r)  
    {  
        if(x[mid]==num)return mid;  
        else if(x[mid]<num)l=mid+1;  
        else r=mid-1;  
        mid=(l+r)>>1;  
    }  
}  
int main()  
{  
    int n,i,j,k,all;  
    int a[2222],b[2222];  
    char s[2222][3];  
    while(scanf("%d",&n)==1)  
    {  
        j=0;  
        for(i=0; i<n; i++)  
        {  
            scanf("%d%d%s",&a[i],&b[i],s[i]);  
            x[j++]=a[i]-1;  
            x[j++]=a[i];  
            x[j++]=a[i]+1;  
            x[j++]=b[i]-1;  
            x[j++]=b[i];  
            x[j++]=b[i]+1;  
        }  
        sort(x,x+j);  
        all=0;  
        for(i=1; i<j; i++)  
            if(x[i]!=x[i-1])x[++all]=x[i];  
  
        build(1,all,1);  
        for(i=0; i<n; i++)  
        {  
            int tema=sea(a[i],0,all);  
            int temb=sea(b[i],0,all);  
  
            if(s[i][0]=='w')update(1,all,1,tema,temb,1);  
            else update(1,all,1,tema,temb,0);  
        }  
  
        if(sum[1].len<=0)printf("Oh, my god\n");  
        else  
        {  
            int ansl=query(1,all,1);  
            int ansr=ansl+sum[1].len-1;  
            printf("%d %d\n",ansl,ansr);  
        }  
    }  
    return 0;  
}  


