#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int ans,point[N],cnt(1),n,k,x,y,next[N*2],temp,f1[N],f2[N],m,d1[N],d2[N];
struct use{int en,v;}e[N*2];
void add(int x,int y){next[++cnt]=point[x];point[x]=cnt;e[cnt].en=y;e[cnt].v=1;}
void dfs(int x,int fa){
   for (int i=point[x];i;i=next[i])
     if (e[i].en!=fa){
        dfs(e[i].en,x);int t=e[i].v+f1[e[i].en];
        if (t>f1[x])f2[x]=f1[x],f1[x]=t,d2[x]=d1[x],d1[x]=i;
        else if (t>f2[x]) f2[x]=t,d2[x]=i;
     }  
   if (f1[x]+f2[x]>temp) temp=f1[x]+f2[x],m=x;
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<n;i++){scanf("%d%d",&x,&y);add(x,y);add(y,x);}
    ans=2*(n-1);
	dfs(1,0);
	ans=ans-temp+1;
	temp=0;
    if (k==2){
       memset(f1,0,sizeof(f1));memset(f2,0,sizeof(f2));
       for (int i=d1[m];i;i=d1[e[i].en]) e[i].v=e[i^1].v=-1;    
       for (int i=d2[m];i;i=d1[e[i].en]) e[i].v=e[i^1].v=-1;
       dfs(1,0);
	   ans=ans-temp+1;
    }
   cout<<ans<<endl;
} 


