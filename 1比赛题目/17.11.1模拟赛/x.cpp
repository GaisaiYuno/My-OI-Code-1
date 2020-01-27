#include<cstdio>  
#include<algorithm>  
using namespace std;  
int T;  
int M,N,L;  
struct Job  
{  
    int a,b,t,u,v,w,x;  
    int state;  
    bool operator<(const Job& j)const  
    {  
        return (t<j.t) || (t==j.t && v>j.v);   
    }  
};  
const int maxl=10000+10;  
Job j[maxl];  
int main()  
{  
    int kase=1;  
    while(scanf("%d",&T)==1 && T!=0)  
    {  
        scanf("%d%d%d",&M,&N,&L);  
        int money=0;  
        for(int i=0;i<L;i++)  
        {  
            int a,b,t,u,v,w,x;  
            scanf("%d%d%d%d%d%d%d",&a,&b,&t,&u,&v,&w,&x);  
            j[i]={a,b,t,u,v,w,x,0};  
        }  
        sort(j,j+L);  
        for(int i=0;i<T;i++)  
        {  
            int m=M;  
            int n=N;  
            for(int s=0;s<L;s++)  
            {  
                if(j[s].t>i)  
                    break;  
                if(!j[s].state && m>=j[s].a && n>=j[s].b)  
                {  
                    m-=j[s].a;  
                    n-=j[s].b;  
                    j[s].state=1;  
                    money+=j[s].v;  
                    if(i+1<=j[s].u)  
                        money+=(j[s].u-i-1)*j[s].w;  
                    else  
                        money+=(j[s].u-i-1)*j[s].x;  
                }  
            }  
        }  
        for(int s=0;s<L;s++)  
            if(!j[s].state && j[s].u<=T)  
                money-=(T-j[s].u)*j[s].x;  
        printf("Case %d: %d\n\n",kase++,money);  
    }  
    return 0;  
}  
/*
#include <stdio.h> 
#include <math.h> 
#define pi 3.141592653 
  
int main() 
{ 
    double r1=0,r2,x,y; 
    int n; 
    scanf("%d",&n); 
    for(int i=1;i<=n;i++) 
    { 
        scanf("%lf%lf",&x,&y); 
        double distance=x*x+y*y; 
        int year=1; 
  
        for(r1=0;r2=(100/pi+r1*r1),r2<distance;r1=sqrt(r2)) 
            year++; 
  
        printf("Property %d: This property will begin eroding in year %d.\n",i,year); 
    } 
    printf("END OF OUTPUT.\n"); 
    return 0; 
} 
*/
