#include<iostream>
using namespace std;
int dis[1001][1001]; 
int maxx[1001],maxy[1001];
int m,l;
#define f(i,a,b) for(i=a;i<=b;i++) //简化代码
int main()
{
//	freopen("testdata (13).in","r",stdin);
    int n,s,i,j,k;
    cin>>n>>s;
    f(i,0,1000)
    {
        f(j,0,1000)
        {
            if(i!=j)dis[i][j]=99999999;
            else dis[i][j]=0;
        }
    }
    f(i,1,n-1)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b]=c;
        dis[b][a]=c;//无向图存图
    }
    int maxn=0;
    f(k,1,n)
    {
        f(i,1,n)
        {
            f(j,1,n)if(dis[i][j]>dis[i][k]+dis[k][j])dis[i][j]=dis[i][k]+dis[k][j];
        }
    }//floyd求直径
    f(i,1,n)
    {
        f(j,1,n)
        {
        //	printf("%d ",dis[i][j]);
            if(dis[i][j]!=99999999)
            {
                if(maxn<dis[i][j])maxn=dis[i][j];
            }
        }   
       // printf("\n");
    } //因为有多条直径，所以要把直径先求出
   // printf("%d\n",maxn);
    f(i,1,n)
    {
        f(j,1,n)
        {
            if(maxn==dis[i][j])
            {
                m++;
                maxx[m]=i;
                maxy[m]=j;
//                printf("%d %d\n",i,j);
            }
        }   
    } //然后把所有端点放到数组里,方便枚举
 //   printf("%d",m);
    int minn=99999999;
    f(i,1,n)
    {
        f(j,1,n)//枚举树网的中心(因为树网的中心可能退化成一个点,所以无需判重)
        {
            int ans=0;
            f(l,1,m)//枚举直径
            {
                if(dis[i][j]!=99999999&&dis[i][j]<=s&&dis[maxx[l]][i]+dis[i][j]+dis[j][maxy[l]]==maxn)//判断线段是否在直径l上
                {
                    f(k,1,n)//枚举所有点的偏心距
                    {
                        if(k!=i&&k!=j)//判重
                        ans=max(ans,(dis[k][i]+dis[k][j]-dis[i][j])/2);//判断点k到线段(i,j)的距离
//                        printf("%d\n",ans); 
                    }
                    minn=min(minn,ans);//最小偏心距
                }
            }
        }
    }
    cout<<minn;//~~华丽的输出~~
}
