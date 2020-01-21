#include<iostream>
#include<cstdio>
using namespace std;
int n,m,v[30],sv[30],g[20][30],s[20],top;
int as[20],sum=1000000000;
void dfs(int k,int cnt)//第k层对第k种饲料惊醒处理，cnt记录已选择饲料的种数 
{
    if(k>n) //当第n种饲料处理完就可以进行更新了 
    {
        bool flag=true;
        for(register int i=1;i<=m;++i)
        if(sv[i]<v[i]){flag=false;break;}//判断是否喂饱牛 
        if(flag)
        if(cnt<sum)//因为我们是从第一种饲料开始逐层处理，而且
        {           //所以答案是从字典序小的开始更新 
            sum=cnt;
            for(register int i=1;i<=n;++i)//用一个队列存储答案 
            as[i]=s[i];
        }
        return;
    }
    s[++top]=k;//队列存储饲料种类 
    for(register int i=1;i<=m;++i)sv[i]+=g[k][i];//sv[i]存目前维生素总量 
    dfs(k+1,cnt+1);//选取 
    for(register int i=1;i<=m;++i)sv[i]-=g[k][i];
    --top;//回溯 
    dfs(k+1,cnt);//不选取 
}
int main()
{
scanf("%d",&m);
    for(register int i=1;i<=m;++i)
    scanf("%d",&v[i]);
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)
    for(register int j=1;j<=m;++j)
    scanf("%d",&g[i][j]);
    dfs(1,0);
    printf("%d ",sum);
    for(register int i=1;i<=sum;++i)
    printf("%d ",as[i]);
    return 0;
}	
